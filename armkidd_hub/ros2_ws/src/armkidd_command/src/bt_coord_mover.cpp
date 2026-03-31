#pragma once
#include <rclcpp/rclcpp.hpp>
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include <behaviortree_cpp/bt_factory.h>

#include <visualization_msgs/msg/marker.hpp>

#include <ament_index_cpp/get_package_share_directory.hpp>
#include "armkidd_interfaces/msg/world_target.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include <moveit/robot_state/robot_state.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <moveit/planning_scene_monitor/current_state_monitor.hpp>
#include <moveit/robot_model_loader/robot_model_loader.hpp>


#include "armkidd_command/config_loader.hpp"
#include "armkidd_command/TF_helper.hpp"
#include "armkidd_command/gripper_moveit_handler.hpp"
#include "armkidd_command/arm_moveit_handler.hpp"

#include "armkidd_command/bt_nodes/WaitForCommand.hpp"
#include "armkidd_command/bt_nodes/GoToTarget.hpp"
#include "armkidd_command/bt_nodes/CloseGripper.hpp"
#include "armkidd_command/bt_nodes/Retreive.hpp"
#include "armkidd_command/bt_nodes/PlaceDown.hpp"
#include "armkidd_command/bt_nodes/BackToDefault.hpp"

#include <std_msgs/msg/string.hpp>


using WorldTarget = armkidd_interfaces::msg::WorldTarget;

class BTCoordMover : public rclcpp::Node
{
    public:
        BTCoordMover() : Node("bt_coord_mover")
        {        
            rclcpp::CallbackGroup::SharedPtr jointStateCallbackGroup = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);;

            cmdReceive = this->create_subscription<WorldTarget>("/armkidd_bbox_target", 10, std::bind(&BTCoordMover::getCmd, this, std::placeholders::_1)); 
            graspReceive = this->create_subscription<std_msgs::msg::String>("grasping_call", 10, std::bind(&BTCoordMover::grippedCallback, this, std::placeholders::_1));
        
            obsPub = this->create_publisher<std_msgs::msg::String>("/cmd_display_obstacles", 10);

            tfBuffer = std::make_shared<tf2_ros::Buffer>(this->get_clock());
            tfBuffer->setUsingDedicatedThread(true);
            tfListener = std::make_shared<tf2_ros::TransformListener>(*tfBuffer); // listenes to TF changes

            auto subOptions = rclcpp::SubscriptionOptions();
            subOptions.callback_group = jointStateCallbackGroup;

            jointStateSub = this->create_subscription<sensor_msgs::msg::JointState>("/joint_states", 10, std::bind(&BTCoordMover::setLatestJointState, this, std::placeholders::_1), subOptions);

            gripResetTimer = this->create_wall_timer(std::chrono::seconds(2), std::bind(&BTCoordMover::gripStateReset, this));
            configTimer = this->create_wall_timer(std::chrono::seconds(2), std::bind(&BTCoordMover::checkConfig, this));
            
            RCLCPP_INFO(this->get_logger(), "BTCoordMover node started");    
        }

        void init()
        {
            moveit::planning_interface::MoveGroupInterfacePtr moveGroupArm;
            moveit::planning_interface::MoveGroupInterfacePtr moveGroupGripper;

            initMoveit(moveGroupArm, moveGroupGripper);

            tfHelper = std::make_shared<TFHelper>(shared_from_this());
            tfHelper->setTFFrames(tfBuffer, moveGroupArm->getPlanningFrame(), "camera_head_link");

            initTree();
            
            updateConfigs();

            createBoundaries();

            RCLCPP_WARN(this->get_logger(), "\n\n ---- BTCoordMover node initialised ---- \n");  
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

        void updateConfigs()
        {
            try
            {
                ConfigLoader cfgOffsets("runtime_ros2", "target_offsets", configPath);

                float xOffsetScale = cfgOffsets.get<float>("x_offset");
                float yOffsetScale = cfgOffsets.get<float>("y_offset");
                float zOffsetScale = cfgOffsets.get<float>("z_offset");
                float camera_angle = cfgOffsets.get<float>("cam_angle");

                tfHelper->setPointParams(camera_angle, xOffsetScale, yOffsetScale, zOffsetScale);

                ConfigLoader cfgSettings("runtime_ros2", "arm_settings", configPath);

                tree.rootBlackboard()->set("reach_forward", cfgSettings.get<float>("reach_forward"));
                tree.rootBlackboard()->set("raise_distance", cfgSettings.get<float>("raise_distance"));
                tree.rootBlackboard()->set("grip_timeout", cfgSettings.get<float>("grip_timeout"));

                RCLCPP_INFO(this->get_logger(), "Offsets -> x: %.3f | y: %.3f | z: %.3f | cam_angle: %.3f", xOffsetScale, yOffsetScale, zOffsetScale, camera_angle);
            }
            catch (const std::exception &e)
            {
                RCLCPP_WARN(this->get_logger(), "Config check failed: %s", e.what());
            }
        }

        void initMoveit(moveit::planning_interface::MoveGroupInterfacePtr& moveGroupArm, moveit::planning_interface::MoveGroupInterfacePtr& moveGroupGripper) 
        {
            robotModelLoader = std::make_shared<robot_model_loader::RobotModelLoader>(shared_from_this(), "robot_description");

            robotModel = robotModelLoader->getModel();

            currentStateMonitor = std::make_shared<planning_scene_monitor::CurrentStateMonitor>(shared_from_this(), robotModel, tfBuffer, false);        
            currentStateMonitor->startStateMonitor();

            if (!currentStateMonitor->waitForCurrentState(this->get_clock()->now(), 5.0))
                RCLCPP_WARN(get_logger(), "No current robot state received within timeout.");
            
            moveGroupArm = std::make_shared<moveit::planning_interface::MoveGroupInterface>(shared_from_this(), "arm");
            moveGroupGripper = std::make_shared<moveit::planning_interface::MoveGroupInterface>(shared_from_this(), "gripper");

            armMoveitHandler = std::make_shared<ArmMoveitHandler>(shared_from_this(), moveGroupArm, tfBuffer);
            gripperMoveitHandler = std::make_shared<GripperMoveitHandler>(shared_from_this(), moveGroupGripper);
        }

        void initTree()
        {
            factory.registerNodeType<WaitForCommand>("WaitForCommand");
            factory.registerNodeType<GoToTarget>("GoToTarget");
            factory.registerNodeType<CloseGripper>("CloseGripper");
            factory.registerNodeType<Retreive>("Retreive");
            factory.registerNodeType<PlaceDown>("PlaceDown");
            factory.registerNodeType<BackToDefault>("BackToDefault");
            
            std::string treePath = ament_index_cpp::get_package_share_directory("armkidd_command") + "/behavior_trees/arm_tree.xml";

            auto blackboard = BT::Blackboard::create();
            blackboard->set("node", shared_from_this());
            blackboard->set<WorldTarget::SharedPtr>("currentCmd", nullptr);
            blackboard->set("tfHelper", tfHelper);
            blackboard->set("obsPub", obsPub);
            blackboard->set("grippedState", false);
            blackboard->set("armMoveitHandler", armMoveitHandler);
            blackboard->set("gripperMoveitHandler", gripperMoveitHandler);
            blackboard->set("smallObj", true);

            tree = factory.createTreeFromFile(treePath, blackboard);

            treeTimer = create_wall_timer(std::chrono::milliseconds(100), std::bind(&BTCoordMover::tickTree, this));
        }

        void getCmd(const WorldTarget::SharedPtr msg)
        {           
            tree.rootBlackboard()->set("currentCmd", msg);
        }

        void grippedCallback(const std_msgs::msg::String::SharedPtr msg)
        {
            RCLCPP_INFO(get_logger(), "Gripped Callback.");

            tree.rootBlackboard()->set("grippedState", true);
            gripResetTimer->cancel();
            gripResetTimer->reset();
        }

        void gripStateReset()
        {
            tree.rootBlackboard()->set("grippedState", false);
        }

        moveit_msgs::msg::CollisionObject makeBox(const std::string& id, std::array<double, 3> dims, std::array<double, 3> pos)
        {
            moveit_msgs::msg::CollisionObject obj;
            obj.header.frame_id = "base_link";
            obj.id = id;

            shape_msgs::msg::SolidPrimitive primitive;
            primitive.type = primitive.BOX;
            primitive.dimensions = {dims[0], dims[1], dims[2]};

            geometry_msgs::msg::Pose pose;
            pose.position.x = pos[0];
            pose.position.y = pos[1];
            pose.position.z = pos[2];
            pose.orientation.w = 1.0;

            obj.primitives.push_back(primitive);
            obj.primitive_poses.push_back(pose);
            obj.operation = obj.ADD;

            return obj;
        };
        
        void createBoundaries()
        {
            moveit::planning_interface::PlanningSceneInterface psi;

            std::vector<moveit_msgs::msg::CollisionObject> objects;

            objects.push_back(makeBox("x_limit_wall", {0.01, 10.0, 10.0}, {4.0, 0.0, 0.0}));
            objects.push_back(makeBox("ground_plane", {20.0, 20.0, 0.01}, {0.0, 0.0, -0.1}));

            psi.applyCollisionObjects(objects);
        }
        
        void setLatestJointState(const sensor_msgs::msg::JointState::SharedPtr msg)
        {
            armMoveitHandler->setLatestJointState(msg);
        }

    private:

        void tickTree()
        {
            auto status = tree.tickOnce();
        }

        rclcpp::Subscription<WorldTarget>::SharedPtr cmdReceive;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr obsPub;

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr graspReceive;
        rclcpp::TimerBase::SharedPtr gripResetTimer;

        rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr jointStateSub;

        // TF Handlers

        std::shared_ptr<tf2_ros::Buffer> tfBuffer;
        std::shared_ptr<tf2_ros::TransformListener> tfListener;
        std::shared_ptr<TFHelper> tfHelper;

        // Robot Loaders

        moveit::core::RobotModelPtr robotModel;
        robot_model_loader::RobotModelLoaderPtr robotModelLoader;
        planning_scene_monitor::CurrentStateMonitorPtr currentStateMonitor;

        // Moveit Handlers

        std::shared_ptr<ArmMoveitHandler> armMoveitHandler;
        std::shared_ptr<GripperMoveitHandler> gripperMoveitHandler;

        // Tree Handlers

        BT::Tree tree;
        BT::BehaviorTreeFactory factory;
        rclcpp::TimerBase::SharedPtr treeTimer;

        // Config controls
        
        std::string configPath = "/home/jetsonalex/Armkidd/shared/config.yaml";
        std::filesystem::file_time_type lastWriteTime;
        rclcpp::TimerBase::SharedPtr configTimer;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BTCoordMover>();
    node->init();

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}