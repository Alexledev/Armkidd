#pragma once

#include <behaviortree_cpp/bt_factory.h>

#include "armkidd_command/gripper_moveit_handler.hpp"
#include "armkidd_command/arm_moveit_handler.hpp"

class PlaceDown : public BT::StatefulActionNode
{
    public:

        PlaceDown(const std::string& name, const BT::NodeConfiguration& config) : BT::StatefulActionNode(name, config) {}

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
            
            raiseDistance = blackboard->get<float>("raise_distance");

            return BT::NodeStatus::RUNNING;
        }

        BT::NodeStatus onRunning()
        {
            try
            {   
                RCLCPP_INFO(node->get_logger(), "Retreive");    

                armMoveitHandler->moveOffset(0.0, 0.0, -raiseDistance * 0.8f);
                RCLCPP_INFO(node->get_logger(), "Place Down");  

                gripperMoveitHandler->openGripper();
                RCLCPP_INFO(node->get_logger(), "Opened Gripper");    

                armMoveitHandler->moveOffset(0.0, 0.0, raiseDistance * 0.8f);
                RCLCPP_INFO(node->get_logger(), "Raise Arm"); 
                
                armMoveitHandler->turnWrist(false);
                RCLCPP_INFO(node->get_logger(), "Rotate Back");  

                return BT::NodeStatus::SUCCESS;
            }
            catch (const std::exception& e)
            {
                RCLCPP_ERROR(node->get_logger(), "Exception in PlaceDown node: %s", e.what());
                return BT::NodeStatus::FAILURE;
            }
            catch (...)
            {
                RCLCPP_ERROR(node->get_logger(), "Unknown exception in PlaceDown node");
                return BT::NodeStatus::FAILURE;
            }
        }

        void onHalted() { }

    private:  

        float raiseDistance = 0.6f;

        rclcpp::Node::SharedPtr node;        
        std::shared_ptr<ArmMoveitHandler> armMoveitHandler;
        std::shared_ptr<GripperMoveitHandler> gripperMoveitHandler;
};