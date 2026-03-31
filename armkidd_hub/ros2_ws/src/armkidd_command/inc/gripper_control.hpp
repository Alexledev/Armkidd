#ifndef GRIPPER_CONTROL
#define GRIPPER_CONTROL

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/robot_state/robot_state.hpp>
#include "utils.h" 
#include "transmit_modal.h"

class Gripper_Control
{
public:
    enum GripperMoveStates
    {
        gripper_ready,
        gripper_moving,
        gripper_complete
    };

    Gripper_Control(moveit::planning_interface::MoveGroupInterfacePtr gripper_group) : _gripper_group(gripper_group)
    {

    }

    GripperMoveStates getCurrentState()
    {
        return current_state;
    }

    void setCurrentState(GripperMoveStates state)
    {
        current_state = state;
    }

    bool isReady()
    {
        return true; //(current_state == gripper_complete || current_state == gripper_ready);
    }
    
    void handleControl(TransmitStates state)
    {
        switch (state)
        {
            case TransmitStates::RestComplete:

                rclcpp::sleep_for(std::chrono::seconds(1));

                moveToRestGripper();
                break;

            case TransmitStates::GripperCloseComplete:

                setCurrentState(gripper_complete);
                RCLCPP_INFO(rclcpp::get_logger("Gripper_Control"), "IRL Gripper close success...");
                break;

            case TransmitStates::GripperOpenComplete:

                setCurrentState(gripper_complete);
                RCLCPP_INFO(rclcpp::get_logger("Gripper_Control"), "IRL Gripper open success...");
                break;

            case TransmitStates::GripperGraspComplete:

                setCurrentState(gripper_complete);
                RCLCPP_INFO(rclcpp::get_logger("Gripper_Control"), "IRL Gripper grasp success...");
                break;

            default:
                break;
        }
    }

    void moveToRestGripper()
    {               
        _gripper_group->setStartStateToCurrentState();

        _gripper_group->setNamedTarget("rest");
        RCLCPP_INFO(rclcpp::get_logger("Gripper_Control"), ">>>> Setting rest state for gripper");

        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success = (_gripper_group->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);

        if (success)
        {      
            _gripper_group->asyncExecute(plan);
        }
        else
        {
            RCLCPP_WARN(rclcpp::get_logger("Gripper_Control"), "Planning to target failed.");
        }
    }

    void parseData(const trajectory_msgs::msg::JointTrajectory& joint_traj, std::vector<std::vector<float>>& traj_vec)
    {        

        // isClosed = joint_traj.points.front().positions[0] <= joint_traj.points.back().positions[0];
        if (joint_traj.points.size() > 1)
        {
            isClosed = joint_traj.points[0].positions[0] <= joint_traj.points[1].positions[0];
        }
        else if (!joint_traj.points.empty())
        {
            isClosed = joint_traj.points[0].positions[0] <= 0.0; // Assume closing if already at a position
        }

        std::vector<float> h_vec = {
                static_cast<float>(joint_traj.points.size()),
                static_cast<float>(1),
                static_cast<float>(isClosed ? TransmitStates::GripperClose : TransmitStates::GripperOpen),
                static_cast<float>(0)     
            };                


        traj_vec.emplace_back(h_vec);  

        for (size_t i = 0; i < joint_traj.points.size(); ++i)
        {
            const auto& point = joint_traj.points[i];

            std::vector<float> p_vec = {
                static_cast<float>(point.positions[0]), 
            };  

            traj_vec.emplace_back(p_vec);    
        }     
    }

private:
    moveit::planning_interface::MoveGroupInterfacePtr _gripper_group;
    // TransmitStates transmission_type = TransmitStates::GripperClose;
    GripperMoveStates current_state = GripperMoveStates::gripper_ready;

    bool isClosed = true;
};

#endif