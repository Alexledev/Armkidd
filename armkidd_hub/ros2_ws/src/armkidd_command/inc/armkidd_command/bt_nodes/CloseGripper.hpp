#pragma once

#include <rclcpp/rclcpp.hpp>
#include <behaviortree_cpp/bt_factory.h>
#include <armkidd_command/gripper_moveit_handler.hpp>

class CloseGripper : public BT::StatefulActionNode
{
    public:

        CloseGripper(const std::string& name, const BT::NodeConfiguration& config) : BT::StatefulActionNode(name, config) {}

        static BT::PortsList providedPorts()
        {
            return { BT::InputPort<bool>("grippedState") };  // declare the port
        }

        BT::NodeStatus onStart()
        {
            auto blackboard = config().blackboard;

            if (!node)
                node = blackboard->get<rclcpp::Node::SharedPtr>("node");

            if (!gripperMoveitHandler)
                gripperMoveitHandler = blackboard->get<std::shared_ptr<GripperMoveitHandler>>("gripperMoveitHandler");

            gripTimeout = blackboard->get<float>("grip_timeout");

            gripperMoveitHandler->closeGripperAsync(blackboard->get<bool>("smallObj"));

            startTime = steadyClock.now();

            RCLCPP_INFO(node->get_logger(), "Closed Gripper");    
            
            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning()
        {
            if ((steadyClock.now() - startTime).seconds() >= gripTimeout)
            {
                gripperMoveitHandler->stop();

                RCLCPP_WARN(node->get_logger(), "Gripper timeout — assuming gripped");
                return BT::NodeStatus::SUCCESS;
            }

            auto grippedState = getInput<bool>("grippedState"); 

            if (!grippedState || !grippedState.value())
            {
                // RCLCPP_WARN(node->get_logger(), "Wait for gripper");
                return BT::NodeStatus::RUNNING;
            }

            gripperMoveitHandler->stop();
            RCLCPP_INFO(node->get_logger(), "Gripped");
            return BT::NodeStatus::SUCCESS;
        }

        void onHalted() { }

    private:       

        rclcpp::Clock steadyClock{RCL_STEADY_TIME};

        float gripTimeout = 5.0f;

        rclcpp::Node::SharedPtr node;        
        std::shared_ptr<GripperMoveitHandler> gripperMoveitHandler;
        rclcpp::Time startTime;
};
