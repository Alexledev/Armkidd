#pragma once

#include <moveit/robot_state/robot_state.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>

class ArmMoveitHandler
{
public:
    ArmMoveitHandler(const rclcpp::Node::SharedPtr node, moveit::planning_interface::MoveGroupInterfacePtr moveGroup, std::shared_ptr<tf2_ros::Buffer> tfBuffer)
    {
        this->moveGroup = moveGroup;
        this->node = node;
        this->tfBuffer = tfBuffer;

        this->moveGroup->setGoalPositionTolerance(goalPosTolerance);
        this->moveGroup->setGoalOrientationTolerance(goalOrientationTolerance);
        this->moveGroup->setMaxVelocityScalingFactor(maxVelocityScaling);
        this->moveGroup->setMaxAccelerationScalingFactor(maxAccelerationScaling);
    }

    bool moveArmToPoint(geometry_msgs::msg::PointStamped point)
    {
        moveit_msgs::msg::Constraints constraints;
        moveit_msgs::msg::JointConstraint jc;

        jc.joint_name = "joint_5";   // <-- your joint
        jc.position = 0.0;              // lock at 0
        jc.tolerance_above = 0.001;
        jc.tolerance_below = 0.001;
        jc.weight = 1.0;

        constraints.joint_constraints.push_back(jc);
        moveGroup->setPathConstraints(constraints);


        RCLCPP_INFO(node->get_logger(), "Setting target: x: %.2f, y: %.2f, z: %.2f", point.point.x, point.point.y, point.point.z);
        moveGroup->setPositionTarget(point.point.x, point.point.y, point.point.z);

        RCLCPP_INFO(node->get_logger(), "Target set, planning...");
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success = (moveGroup->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (success)
        {
            RCLCPP_WARN(node->get_logger(), "Arm Plan successful. Executing...");
            moveGroup->execute(plan);
            return true;
        } 

        RCLCPP_ERROR(node->get_logger(), "Planning failed!");
        return false;
    }

    bool moveOffset(float relX = 0.0, float relY = 0.0, float relZ = 0.0)
    {
        auto currentPose = getCurrentEePose();
        auto target = applyOffset(currentPose, relX, relY, relZ);

        moveGroup->setStartStateToCurrentState();

        // plan and execute
        moveGroup->setPoseTarget(target);

        moveit::planning_interface::MoveGroupInterface::Plan plan;

        for (int i = 0; i < retryAttempts; ++i)
        {
            bool success_A = (moveGroup->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

            if (success_A)
            {
                RCLCPP_WARN(node->get_logger(), "Arm shift planned. Wait...");
                moveGroup->execute(plan);

                moveGroup->stop();
                moveGroup->clearPoseTargets();

                RCLCPP_WARN(node->get_logger(), "Arm shift successful. Executing...");

                return true;
            }
        }

        RCLCPP_ERROR(node->get_logger(), "Arm shift Planning failed!");

        return false;
    }    

    bool moveToNamedTarget(std::string target)
    {
        moveGroup->setNamedTarget(target);

        RCLCPP_INFO(node->get_logger(), "Target set, planning...");
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success = (moveGroup->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (success)
        {            
            RCLCPP_WARN(node->get_logger(), "Arm to target successful. Executing...");
            moveGroup->execute(plan);

            return true;
        }

        RCLCPP_ERROR(node->get_logger(), "Planning failed!");

        return false;
    }
    
    bool rotateWrist(float rad)
    {
        std::map<std::string, double> jointValues = getCurrentJointValues();

        if (jointValues.empty())
        {
            RCLCPP_ERROR(node->get_logger(), "Failed to get current joint values!");
            return false;
        }

        // Override ONLY joint_5, everything else stays at current position
        jointValues["joint_5"] = rad;

        moveGroup->setStartStateToCurrentState();
        moveGroup->setJointValueTarget(jointValues);

        RCLCPP_INFO(node->get_logger(), "Target set, planning...");
        moveit::planning_interface::MoveGroupInterface::Plan plan;

        bool success = (moveGroup->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
        if (success)
        {
            RCLCPP_WARN(node->get_logger(), "Wrist rotation planned. Executing...");
            moveGroup->execute(plan);
            return true;
        }

        RCLCPP_ERROR(node->get_logger(), "Planning failed!");
        return false;
    }

    void moveToDefault()
    {
        moveToNamedTarget("rest");
    }

    void turnWrist(bool twist)
    {
        if (twist)
        {
            rotateWrist(1.37);
        }
        else
        {
            rotateWrist(0);
        }
    }

    void stop()
    {
        moveGroup->stop();
    }

    void setLatestJointState(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        latestJointState = msg;
    }

private:

    geometry_msgs::msg::Pose getCurrentEePose()
    {
        try
        {
            geometry_msgs::msg::TransformStamped tfMsg = tfBuffer->lookupTransform("base_link", moveGroup->getEndEffectorLink(), tf2::TimePointZero);

            geometry_msgs::msg::Pose pose;

            pose.position.x = tfMsg.transform.translation.x;
            pose.position.y = tfMsg.transform.translation.y;
            pose.position.z = tfMsg.transform.translation.z;

            pose.orientation = tfMsg.transform.rotation;

            return pose;
        }
        catch (tf2::TransformException &ex)
        {
            RCLCPP_WARN(node->get_logger(), "TF error: %s", ex.what());
            return geometry_msgs::msg::Pose();
        }
    }

    geometry_msgs::msg::Pose applyOffset(const geometry_msgs::msg::Pose& currentPose, float relX, float relY, float relZ)
    {
        tf2::Quaternion q(currentPose.orientation.x, currentPose.orientation.y, currentPose.orientation.z, currentPose.orientation.w);
        tf2::Matrix3x3 m(q);

        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);

        // remove roll influence
        roll = 0.0;

        tf2::Quaternion qNoRoll;
        qNoRoll.setRPY(roll, pitch, yaw);

        tf2::Matrix3x3 rNoRoll(qNoRoll);
        tf2::Vector3 offsetWorld = rNoRoll * tf2::Vector3(relX, relY, relZ);

        geometry_msgs::msg::Pose target = currentPose;
        target.position.x += offsetWorld.x();
        target.position.y += offsetWorld.y();
        target.position.z += offsetWorld.z();

        return target;
    }

    std::map<std::string, double> getCurrentJointValues()
    {
        RCLCPP_INFO(node->get_logger(), "-- getCurrentJointValues");

        std::map<std::string, double> values;

        if (!latestJointState || latestJointState->name.empty())
        {
            RCLCPP_WARN(node->get_logger(), "No joint state received yet! ");
            return values;
        }

        size_t count = std::min<size_t>(5, latestJointState->name.size());
        for (size_t i = 0; i < count; ++i)
        {
            values[latestJointState->name[i]] = latestJointState->position[i];
        }

        return values;
    }

    const float goalPosTolerance = 0.002;
    const float goalOrientationTolerance = 0.1;
    const float maxVelocityScaling = 0.3;
    const float maxAccelerationScaling = 0.3;

    const int retryAttempts = 5;

    std::shared_ptr<tf2_ros::Buffer> tfBuffer;
    sensor_msgs::msg::JointState::SharedPtr latestJointState;

    moveit::planning_interface::MoveGroupInterfacePtr moveGroup;
    
    rclcpp::Node::SharedPtr node;
    
};