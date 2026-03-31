#pragma once

#include <rclcpp/rclcpp.hpp>

#include <behaviortree_cpp/bt_factory.h>

#include <armkidd_command/TF_helper.hpp>
#include "armkidd_command/gripper_moveit_handler.hpp"
#include "armkidd_command/arm_moveit_handler.hpp"

class GoToTarget : public BT::StatefulActionNode
{
    public:

        GoToTarget(const std::string& name, const BT::NodeConfiguration& config) : BT::StatefulActionNode(name, config) {}

        static BT::PortsList providedPorts()
        {
            return {};
        }

        BT::NodeStatus onStart()
        {
            auto blackboard = config().blackboard;

            if (!node)
                node = blackboard->get<rclcpp::Node::SharedPtr>("node");

            if (!armMoveitHandler)
                armMoveitHandler = blackboard->get<std::shared_ptr<ArmMoveitHandler>>("armMoveitHandler");

            if (!gripperMoveitHandler)
                gripperMoveitHandler = blackboard->get<std::shared_ptr<GripperMoveitHandler>>("gripperMoveitHandler");
            
            reachForward = blackboard->get<float>("reach_forward");

            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning()
        {
            geometry_msgs::msg::PointStamped pts = config().blackboard->get<geometry_msgs::msg::PointStamped>("targetPoint");

            armMoveitHandler->moveArmToPoint(pts);
            RCLCPP_INFO(node->get_logger(), "Move To Target");  

            gripperMoveitHandler->openGripper();
            RCLCPP_INFO(node->get_logger(), "Opened Gripper");    

            armMoveitHandler->moveOffset(reachForward);
            RCLCPP_INFO(node->get_logger(), "Reach Forward");  

            return BT::NodeStatus::SUCCESS;
        }

        void onHalted() { }

    private:       

        float reachForward = 0.6f;

        rclcpp::Node::SharedPtr node;        
        std::shared_ptr<ArmMoveitHandler> armMoveitHandler;
        std::shared_ptr<GripperMoveitHandler> gripperMoveitHandler;
};