#pragma once

#include <behaviortree_cpp/bt_factory.h>

#include "armkidd_command/gripper_moveit_handler.hpp"
#include "armkidd_command/arm_moveit_handler.hpp"

class BackToDefault : public BT::StatefulActionNode
{
    public:

        BackToDefault(const std::string& name, const BT::NodeConfiguration& config) : BT::StatefulActionNode(name, config) {}

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
            
            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning()
        {

            gripperMoveitHandler->closeGripper();
            RCLCPP_INFO(node->get_logger(), "Closed Gripper");    
            
            armMoveitHandler->moveToNamedTarget("rest");;
            RCLCPP_INFO(node->get_logger(), "Moved To Default");    

            return BT::NodeStatus::SUCCESS;
        }

        void onHalted() { }

    private:  

        rclcpp::Node::SharedPtr node;        
        std::shared_ptr<ArmMoveitHandler> armMoveitHandler;
        std::shared_ptr<GripperMoveitHandler> gripperMoveitHandler;
};
