#pragma once

#include <moveit/move_group_interface/move_group_interface.hpp>

class GripperMoveitHandler
{

public:
    GripperMoveitHandler(const rclcpp::Node::SharedPtr node, moveit::planning_interface::MoveGroupInterfacePtr moveGroup)
    {
        this->moveGroup = moveGroup;
        this->node = node;
    }

    void openGripper()
    {
        moveGroup->setNamedTarget("gripper_open");
        bool successOpen = (moveGroup->move() == moveit::core::MoveItErrorCode::SUCCESS);

        if (successOpen)
        {
            RCLCPP_WARN(node->get_logger(), "Gripper Open successful. Executing...");
        }
        else
        {
            RCLCPP_ERROR(node->get_logger(), "Planning failed!");
        }
    }

    void closeGripperAsync(bool small)
    {
        moveGroup->setNamedTarget("gripper_closed");

        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool successPlan = (moveGroup->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (successPlan)
        {
            RCLCPP_INFO(node->get_logger(), "Planning succeeded. Executing async... ");
            moveGroup->asyncExecute(plan);
        }
        else
        {
            RCLCPP_ERROR(node->get_logger(), "Planning failed!");
        }
    }

    void closeGripper()
    {
        moveGroup->setNamedTarget("rest");
        bool successClose = (moveGroup->move() == moveit::core::MoveItErrorCode::SUCCESS);

        if (successClose) 
        {
            RCLCPP_WARN(node->get_logger(), "Gripper Close successful. Executing...");
        } 
        else 
        {
            RCLCPP_ERROR(node->get_logger(), "Planning failed!");
        }
    }

    void stop()
    {
        moveGroup->stop();
    }

private:
    moveit::planning_interface::MoveGroupInterfacePtr moveGroup;
    rclcpp::Node::SharedPtr node;
};