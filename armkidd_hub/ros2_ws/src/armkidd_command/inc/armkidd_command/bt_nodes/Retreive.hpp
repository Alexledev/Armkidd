#pragma once

#include <behaviortree_cpp/bt_factory.h>
#include <armkidd_command/TF_helper.hpp>
#include <armkidd_command/arm_moveit_handler.hpp>

class Retreive : public BT::StatefulActionNode
{
    public:

        Retreive(const std::string& name, const BT::NodeConfiguration& config) : BT::StatefulActionNode(name, config) {}

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
            
            raiseDistance = blackboard->get<float>("raise_distance");

            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning()
        {
            RCLCPP_INFO(node->get_logger(), "Retreive");    

            armMoveitHandler->moveOffset(backDistance, 0.0, raiseDistance);
            RCLCPP_INFO(node->get_logger(), "Back Off");  

            armMoveitHandler->moveToNamedTarget("dropoff_heavy");
            RCLCPP_INFO(node->get_logger(), "Move To Dropoff ");  

            armMoveitHandler->turnWrist(true);
            RCLCPP_INFO(node->get_logger(), "Rotate");  

            return BT::NodeStatus::SUCCESS;
        }

        void onHalted() { }

    private:  

        float backDistance = -0.55f;
        float raiseDistance = 0.6f;

        rclcpp::Node::SharedPtr node;        
        std::shared_ptr<ArmMoveitHandler> armMoveitHandler;
};