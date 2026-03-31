#include <rclcpp/rclcpp.hpp>
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include "geometry_msgs/msg/point_stamped.hpp"
#include <visualization_msgs/msg/marker.hpp>
#include <sstream>
#include <string>
#include <filesystem>

#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/robot_state/robot_state.hpp>

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene_monitor/current_state_monitor.hpp>
#include <moveit/robot_model_loader/robot_model_loader.hpp>
#include <tf2_ros/buffer.h>
#include "armkidd_interfaces/msg/world_target.hpp"
#include "armkidd_command/config_loader.hpp"


#include <std_msgs/msg/string.hpp>


using WorldTarget = armkidd_interfaces::msg::WorldTarget;


class ArmCoordMover : public rclcpp::Node
{
public:
    ArmCoordMover() : Node("arm_coord_mover")
    {        
        cmdReceive = this->create_subscription<WorldTarget>("/armkidd_bbox_target", 10, std::bind(&ArmCoordMover::moveToGoal, this, std::placeholders::_1)); 
        graspReceive = this->create_subscription<std_msgs::msg::String>("grasping_call", 10, std::bind(&ArmCoordMover::grippedCallback, this, std::placeholders::_1));
        
        tfBuffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tfListener = std::make_shared<tf2_ros::TransformListener>(*tfBuffer);

        markerPub = this->create_publisher<visualization_msgs::msg::Marker>("visualized_marker", 10);
        obsPub = this->create_publisher<std_msgs::msg::String>("/cmd_display_obstacles", 10);

    }

    void init()
    {
        robotModelLoader = std::make_shared<robot_model_loader::RobotModelLoader>(shared_from_this(), "robot_description");

        robotModel = robotModelLoader->getModel();

        currentStateMonitor = std::make_shared<planning_scene_monitor::CurrentStateMonitor>(shared_from_this(), robotModel, tfBuffer, false);        
        currentStateMonitor->startStateMonitor();

        if (!currentStateMonitor->waitForCurrentState(this->get_clock()->now(), 5.0))
        {
            RCLCPP_WARN(get_logger(), "No current robot state received within timeout.");
        }

        moveGroupArm = std::make_shared<moveit::planning_interface::MoveGroupInterface>(shared_from_this(), "arm");
        moveGroupGripper = std::make_shared<moveit::planning_interface::MoveGroupInterface>(shared_from_this(), "gripper");

        createBoundary();

        updateConfigs();        
        lastWriteTime = std::filesystem::last_write_time(configPath);

        configTimer =  this->create_wall_timer(std::chrono::seconds(1), std::bind(&ArmCoordMover::checkConfig, this));

        RCLCPP_INFO(this->get_logger(), "ArmCoordMover ready");
    }

    void checkConfig()
    {
        auto current = std::filesystem::last_write_time(configPath);
        if (current != lastWriteTime)
        {
            lastWriteTime = current;
            RCLCPP_INFO(this->get_logger(), "Config changed. Reloading...");
            updateConfigs();
        }
    }

    void createBoundary()
    {
        moveit::planning_interface::PlanningSceneInterface psi;

        moveit_msgs::msg::CollisionObject wall;
        wall.header.frame_id = "base_link";
        wall.id = "x_limit_wall";

        shape_msgs::msg::SolidPrimitive primitive;
        primitive.type = primitive.BOX;
        primitive.dimensions = {0.01, 10.0, 10.0};

        geometry_msgs::msg::Pose pose;
        pose.position.x = 3.6;
        pose.orientation.w = 1.0;

        wall.primitives.push_back(primitive);
        wall.primitive_poses.push_back(pose);
        wall.operation = wall.ADD;

        psi.applyCollisionObject(wall);
    }

    void updateConfigs()
    {
        // std::string str = msg->data;
        try
        {
            ConfigLoader cfgOffsets("runtime_ros2", "target_offsets", configPath);

            xOffsetScale = cfgOffsets.get<float>("x_offset");
            yOffsetScale = cfgOffsets.get<float>("y_offset");
            zOffsetScale = cfgOffsets.get<float>("z_offset");
            camera_angle = cfgOffsets.get<float>("cam_angle");

            ConfigLoader cfgSettings("runtime_ros2", "arm_settings", configPath);

            reachForward = cfgSettings.get<float>("reach_forward");
            raised_Y = cfgSettings.get<float>("raise_distance");

            RCLCPP_INFO(this->get_logger(), "Offsets -> x: %.3f | y: %.3f | z: %.3f | cam_angle: %.3f", xOffsetScale, yOffsetScale, zOffsetScale, camera_angle);
        }
        catch (const std::exception &e)
        {
            RCLCPP_WARN(this->get_logger(), "Config check failed: %s", e.what());
        }
    }

    void moveToGoal(const WorldTarget::SharedPtr msg)
    {
        if (msg->depth == 0)
        {
            RCLCPP_INFO(this->get_logger(), "Data should be > 0");
            return;
        }            

        if (doingAction)
        {
            RCLCPP_INFO(this->get_logger(), "Doing an action rn");
            return;
        }


        float x = msg->target_x * -scaleUp;
        float y = msg->target_y * scaleUp;
        float z = msg->depth * scaleUp;
        float width = msg->width * scaleUp;
        float height = msg->height * scaleUp;

        currentObjWidth = width;
        currentObjHeight = height;

        bool valid = false;
        geometry_msgs::msg::PointStamped pt = getPoint(x, y, z, width, height, valid);

        if (valid == false)
        {
            RCLCPP_INFO(this->get_logger(), "Data isn't valid");
            return;
        }             

        doingAction = true;
        if (moveArmToPoint(pt)) 
        {
            graspObject();     
        }            
    }

    void graspObject()
    {
        // ----- OPEN GRIPPER -----

        openGripper_sub();

        // ----- MOVE TO GRIP -----

        moveOffset_sub(reachForward);

        // ----- Close GRIPPER -----        

        moveGroupGripper->setNamedTarget("gripper_closed");
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success = (moveGroupGripper->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (success) {
            moveGroupGripper->asyncExecute(plan);
            RCLCPP_WARN(this->get_logger(), "Gripper Closing. Executing...");
            readyToReceiveGraspMSG = true;
            RCLCPP_WARN(this->get_logger(), "Waiting fo grasping msg from controller.");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Planning failed!");
        } 
    }

    void grippedCallback(const std_msgs::msg::String::SharedPtr msg)
    {
        if (readyToReceiveGraspMSG)
        {
            moveGroupGripper->stop();
            RCLCPP_WARN(this->get_logger(), "Grasping confimed with message");


            placeDown_large();
            // if (currentObjWidth > 0.4f)
            // {
            //     placeDown_large();
            // }
            // else
            // {
            //     placeDown_small();
            // }

            readyToReceiveGraspMSG = false;

            // ----- MOVE ARM TO DEFAULT (AGAIN) -----

            if (returnToDefaultTimer)
            {
                returnToDefaultTimer->cancel();
            }

            returnToDefaultTimer = this->create_wall_timer(
                std::chrono::milliseconds(2500),
                [this]() {
                    RCLCPP_WARN(this->get_logger(), "New goal timeout: Moving back to default.");
                    moveToDefault_sub();
                    fullCloseGripper_sub();

                    doingAction = false;

                    // ensure one-shot
                    returnToDefaultTimer->cancel();
                }
            );
        }        
        else
        {
            RCLCPP_WARN_STREAM(this->get_logger(), "Grasping received but not in ready state yet with message: " << msg->data);
        }
    }

    
    void placeDown_large()
    {
        // ----- RETRACT ARM -----
        
        RCLCPP_WARN(this->get_logger(), "RETRACT ARM");
        // moveOffset_sub(-backOff_X, 0.0, raised_Y); //backOff_X raised_Y * 1.2

        // ----- MOVE ARM TO DEFAULT -----
        
        RCLCPP_WARN(this->get_logger(), "MOVE ARM TO DROPOFF");
        moveToNamedTarget_sub("dropoff_heavy");

        // ----- PLACE DOWN -----

        RCLCPP_WARN(this->get_logger(), "PLACE DOWN");
        moveOffset_sub(0.0, 0.0, -raised_Y * 0.8f);

        // ----- OPEN GRIPPER (Temp, replace wiht place down later) -----

        RCLCPP_WARN(this->get_logger(), "OPEN GRIPPER");
        openGripper_sub();

        // ----- RAISE ARM -----

        RCLCPP_WARN(this->get_logger(), "RAISE ARM");
        moveOffset_sub(0.0, 0.0, raised_Y * 0.8f);

        // ----- Close GRIPPER -----

        // fullCloseGripper_sub();


        RCLCPP_WARN(this->get_logger(), "action sequence successful!");
    }

    // void placeDown_small()
    // {
    //     // ----- RETRACT ARM -----
        
    //     moveOffset_sub(0.0, 0.0, raised_Y);

    //     // ----- MOVE ARM TO DEFAULT -----

    //     moveToNamedTarget_sub("dropoff_light");

    //     // ----- EXTEND ARM -----
        
    //     moveOffset_sub(0.2f, 0.0, -0.1);

    //     // ----- PLACE DOWN -----

    //     moveOffset_sub(0.0, 0.0, -raised_Y);

    //     // ----- OPEN GRIPPER (Temp, replace wiht place down later) -----

    //     openGripper_sub();

    //     // ----- RAISE ARM -----

    //     moveOffset_sub(0.0, 0.0, raised_Y);

    //     // ----- Close GRIPPER -----

    //     // fullCloseGripper_sub();

    //     RCLCPP_WARN(this->get_logger(), "action sequence successful!");
    // }


private:

    bool moveArmToPoint(geometry_msgs::msg::PointStamped point)
    {
        RCLCPP_INFO(this->get_logger(), "Setting target: x: %.2f, y: %.2f, z: %.2f", point.point.x, point.point.y, point.point.z);
        moveGroupArm->setPositionTarget(point.point.x, point.point.y, point.point.z);

        RCLCPP_INFO(this->get_logger(), "Target set, planning...");
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success_A = (moveGroupArm->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (success_A) 
        {
            RCLCPP_WARN(this->get_logger(), "Arm Plan successful. Executing...");
            moveGroupArm->execute(plan);
            return true;
        } 
        else 
        {
            RCLCPP_ERROR(this->get_logger(), "Planning failed!");
            return false;
        }
    }

    geometry_msgs::msg::PointStamped getPoint(float x, float y, float z, float width, float height, bool& valid) {

        geometry_msgs::msg::PointStamped pointBefore;
        pointBefore.header.frame_id = "camera_head_link";
        pointBefore.header.stamp = this->get_clock()->now();

        // Camera coords (forward z, up y, right x) to Arm coords (forward x, up z, left y)
        pointBefore.point.x = z;
        pointBefore.point.y = x; 
        pointBefore.point.z = y;
       
        geometry_msgs::msg::PointStamped pointBase;

        // RCLCPP_INFO(this->get_logger(), "Finding target: x: %.2f, y: %.2f, z: %.2f", targetPoint.point.x, targetPoint.point.y, targetPoint.point.z);
        transformPointTF(pointBase, pointBefore);
        
        float nc = std::cos(camera_angle);
        float ns = std::sin(camera_angle);
       
        pointBase.point.x = (ns * pointBefore.point.x + nc  * pointBefore.point.z) + xOffsetScale;// - 0.85f; //  - 0.95f // + 1.4f
        pointBase.point.y = pointBefore.point.y - 1.0f  * yOffsetScale;  // unchanged axis
        pointBase.point.z = height - 0.5f  * zOffsetScale; ///2.0f + 0.4f;

        RCLCPP_WARN(get_logger(), "Point base tf: x=%.3f y=%.3f z=%.3f", pointBase.point.x, pointBase.point.y, pointBase.point.z);

        RCLCPP_INFO(this->get_logger(), "Offsets 2 -> x: %.3f | y: %.3f | z: %.3f | cam_angle: %.3f",
                                            xOffsetScale, yOffsetScale, zOffsetScale, camera_angle);

        std::ostringstream ss;
        ss << pointBase.point.x << ";" << pointBase.point.y << ";";
        std_msgs::msg::String strMsg;
        strMsg.data = ss.str();

        obsPub->publish(strMsg);

        drawMarker(pointBase, 0);

        valid = true;

        if (pointBase.point.x < 1.0f || pointBase.point.x > 4.0f)
        {
            RCLCPP_ERROR(this->get_logger(), "Invalid X location lol");
            valid = false;
        }

        return pointBase;
    }

    void drawMarker(geometry_msgs::msg::PointStamped &point_base, int id = 0, float r = 1.0f, float g = 0.2f, float b = 0.2f)
    {
        visualization_msgs::msg::Marker marker;
        marker.header = point_base.header;
        marker.ns = "detected_target";
        marker.id = id;
        marker.type = visualization_msgs::msg::Marker::SPHERE;
        marker.action = visualization_msgs::msg::Marker::ADD;
        marker.pose.position.x = point_base.point.x;
        marker.pose.position.y = point_base.point.y;
        marker.pose.position.z = point_base.point.z;
        marker.pose.orientation.w = 1.0;
        marker.scale.x = 0.05;
        marker.scale.y = 0.05;
        marker.scale.z = 0.05;
        marker.color.a = 1.0;
        marker.color.r = r;
        marker.color.g = g;
        marker.color.b = b;

        markerPub->publish(marker);
    }

    const void transformPointTF(geometry_msgs::msg::PointStamped &point_base, geometry_msgs::msg::PointStamped &point)
    {
        try
        {
            if (!tfBuffer->canTransform(moveGroupArm->getPlanningFrame(), "camera_head_link", tf2::TimePointZero, tf2::durationFromSec(1.0)))
            {
                RCLCPP_WARN(get_logger(), "Transform not yet available.");
            }

            point_base = tfBuffer->transform(point, moveGroupArm->getPlanningFrame(), tf2::durationFromSec(0.5));
        }
        catch (tf2::TransformException &ex)
        {
            RCLCPP_WARN(this->get_logger(), "TF transform failed: %s", ex.what());
        }
    }

    // ---- sub movement functions ----

    void moveOffset_sub(float rel_x = 0.0, float rel_y = 0.0, float rel_z = 0.0)
    {
        // Get end effector link to move forward
        geometry_msgs::msg::TransformStamped tfMsg = tfBuffer->lookupTransform("base_link", moveGroupArm->getEndEffectorLink(), tf2::TimePointZero);

        geometry_msgs::msg::Pose currentPose;
        currentPose.position.x = tfMsg.transform.translation.x;
        currentPose.position.y = tfMsg.transform.translation.y;
        currentPose.position.z = tfMsg.transform.translation.z;
        currentPose.orientation = tfMsg.transform.rotation;

        tf2::Quaternion q(currentPose.orientation.x, currentPose.orientation.y, currentPose.orientation.z, currentPose.orientation.w);
        // tf2::Matrix3x3 R(q);

        tf2::Matrix3x3 m(q);

        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);

        // remove roll influence
        roll = 0.0;

        tf2::Quaternion q_no_roll;
        q_no_roll.setRPY(roll, pitch, yaw);

        tf2::Matrix3x3 R_no_roll(q_no_roll);

        tf2::Vector3 offset_world = R_no_roll * tf2::Vector3(rel_x, rel_y, rel_z);

        geometry_msgs::msg::Pose target = currentPose;
        target.position.x += offset_world.x();
        target.position.y += offset_world.y();
        target.position.z += offset_world.z();

        moveGroupArm->setStartStateToCurrentState();

        moveGroupArm->setGoalPositionTolerance(0.002);
        moveGroupArm->setGoalOrientationTolerance(0.1);
        moveGroupArm->setMaxVelocityScalingFactor(0.3);
        moveGroupArm->setMaxAccelerationScalingFactor(0.3);

        // plan and execute
        moveGroupArm->setPoseTarget(target);

        moveit::planning_interface::MoveGroupInterface::Plan plan;

        for (int i = 0; i < 5; ++i)
        {
            bool success_A = (moveGroupArm->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

            if (success_A)
            {
                RCLCPP_WARN(this->get_logger(), "Arm shift planned. Wait...");
                moveGroupArm->execute(plan);

                moveGroupArm->stop();
                moveGroupArm->clearPoseTargets();

                RCLCPP_WARN(this->get_logger(), "Arm shift successful. Executing...");

                return;
            }
        }

        RCLCPP_ERROR(this->get_logger(), "Arm shift Planning failed!");
    }
   
    void openGripper_sub()
    {
        moveGroupGripper->setNamedTarget("gripper_open");
        bool successOpen = (moveGroupGripper->move() == moveit::core::MoveItErrorCode::SUCCESS);

        if (successOpen)
        {
            RCLCPP_WARN(this->get_logger(), "Gripper Open successful. Executing...");
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Planning failed!");
        }
    }

    void fullCloseGripper_sub()
    {
        moveGroupGripper->setNamedTarget("default");
        bool successClose = (moveGroupGripper->move() == moveit::core::MoveItErrorCode::SUCCESS);

        if (successClose) {
            RCLCPP_WARN(this->get_logger(), "Gripper Close successful. Executing...");
        } else {
            RCLCPP_ERROR(this->get_logger(), "Planning failed!");
        }
    }

    void moveToNamedTarget_sub(std::string target)
    {
        moveGroupArm->setNamedTarget(target);

        RCLCPP_INFO(this->get_logger(), "Target set, planning...");
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success = (moveGroupArm->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (success)
        {
            RCLCPP_WARN(this->get_logger(), "Arm to target successful. Executing...");
            moveGroupArm->execute(plan);

            moveGroupArm->stop();
            moveGroupArm->clearPoseTargets();
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Planning failed!");
        }
    }

    void moveToDefault_sub()
    {
        moveGroupArm->setNamedTarget("rest"); //default

        RCLCPP_INFO(this->get_logger(), "Target set, planning...");
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success = (moveGroupArm->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (success)
        {
            RCLCPP_WARN(this->get_logger(), "Arm to Default successful. Executing...");
            moveGroupArm->execute(plan);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Planning failed!");
        }
    }

    // --- physical robot stuff ----

    rclcpp::TimerBase::SharedPtr jointTimer;
    moveit::core::RobotModelPtr robotModel;
    robot_model_loader::RobotModelLoaderPtr robotModelLoader;
    planning_scene_monitor::CurrentStateMonitorPtr currentStateMonitor;
    
    // ---- subs and pubs ----

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr configReceive;
    rclcpp::Subscription<WorldTarget>::SharedPtr cmdReceive;
    std::shared_ptr<tf2_ros::Buffer> tfBuffer;
    std::shared_ptr<tf2_ros::TransformListener> tfListener;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr markerPub;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr obsPub;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr graspReceive;
    
    moveit::planning_interface::MoveGroupInterfacePtr moveGroupArm;
    moveit::planning_interface::MoveGroupInterfacePtr moveGroupGripper;

    // ---- detection and movement ----
    
    rclcpp::TimerBase::SharedPtr returnToDefaultTimer;

    float currentObjHeight = 0.0f;
    float currentObjWidth = 0.0f;

    bool gripped = false;
    bool readyToReceiveGraspMSG = false;

    bool doingAction = false;

    // ---- point calculations ----
    
    const float scaleUp = 10.0f; // Scale from meters to cm
    float camera_angle = 28.0f * M_PI / 180.0f; //  * M_PI / 180.0f
    float xOffsetScale = 1.0;
    float yOffsetScale = 1.0;
    float zOffsetScale = 1.0;

    // ---- movement specs ----
    
    const float backOff_X = 0.8f;
    float raised_Y = 0.6f;
    float reachForward = 0.6f;

    // ---- other ----

    std::string configPath = "/home/jetsonalex/Armkidd/shared/config.yaml";
    std::filesystem::file_time_type lastWriteTime;
    rclcpp::TimerBase::SharedPtr configTimer;
    
};


int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto armCoordMover = std::make_shared<ArmCoordMover>();
    armCoordMover->init();

    rclcpp::spin(armCoordMover);
    rclcpp::shutdown();
    return 0;
}