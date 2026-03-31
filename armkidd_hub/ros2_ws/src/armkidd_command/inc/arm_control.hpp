#ifndef ARM_CONTROL
#define ARM_CONTROL

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/robot_state/robot_state.hpp>
#include "transmit_modal.h"

class Arm_Control 
{
    public:
        enum ArmMoveStates 
        {
            arm_ready,
            arm_idle,
            arm_planning,
            arm_moving,
            arm_complete
        };

        Arm_Control(moveit::planning_interface::MoveGroupInterfacePtr arm_group) : _arm_group(arm_group)
        {

        }

        void handleControl(TransmitStates state)
        {
                
            switch(state)
            {
                case TransmitStates::Awaken:                       
                
                    setAwaken();                                    
                    RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Received 'Awaken' command.");
                                        
                    break;

                case TransmitStates::AwakenComplete:                     
                                    
                    setReady();                       
                    RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Received 'Awaken' completion.");
                                        
                    break;

                case TransmitStates::Rest:   

                    setRest();
                    RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Received 'Rest' command.");     

                    break;

                case TransmitStates::RestComplete:                     
                                
                    setClosed();                       
                    RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Received 'Rest' completion.");
                                    
                    break;

                case TransmitStates::ArmMovingComplete:                         

                    setCurrentState(Arm_Control::ArmMoveStates::arm_complete);
                    RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "IRL Arm move success...");

                    break;
                
                default:
                    break;
            }
        }

        ArmMoveStates getCurrentState()
        {
            return current_state;
        }

        void setCurrentState(ArmMoveStates state)
        {
            current_state = state;

            if (current_state == arm_complete)
            {
                transmission_type = TransmitStates::ArmMoving;
            }
        }

        void setAwaken()
        {                      
            if (activated)
                return;

            current_state = arm_ready;
            transmission_type = TransmitStates::Awaken;

             _arm_group->setNamedTarget("default");
            RCLCPP_INFO(rclcpp::get_logger("arm_control"), ">>>> Setting default state for arm");

            moveToPoseArm(_arm_group);
        }

        void setReady()
        {           
            activated = true; 
            current_state = arm_ready;
            transmission_type = TransmitStates::ArmMoving;           
        }

        void setClosed()
        {
            activated = false;   
            current_state = arm_idle; 
        }

        void setRest()
        {
            if (!activated)
                return;
              
            current_state = arm_ready;  
            transmission_type = TransmitStates::Rest;

            _arm_group->setNamedTarget("rest");
            RCLCPP_INFO(rclcpp::get_logger("arm_control"), ">>>> Setting rest state for arm");

            moveToPoseArm(_arm_group);
        }

        bool isReady()
        {
            return (current_state == arm_complete || current_state == arm_ready);
        }

        void moveToPoseArm(std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group)
        {        
            if (current_state != arm_ready) //--
                return;

            current_state = arm_planning;
            move_group->setStartStateToCurrentState();

            moveit::planning_interface::MoveGroupInterface::Plan plan;
            bool success = (move_group->plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
            if (success)
            {        
                auto future = move_group->asyncExecute(plan);

                if (future == moveit::core::MoveItErrorCode::SUCCESS)
                {          
                    current_state = arm_ready;          
                    RCLCPP_INFO(rclcpp::get_logger("arm_control"), "Arm move success~!");
                }
                else
                {
                    RCLCPP_WARN(rclcpp::get_logger("arm_control"), "Arm move failed.");
                }            
            }
            else
            {
                RCLCPP_WARN(rclcpp::get_logger("arm_control"), "Planning to target failed.");
            }
        }

        void parseData(const trajectory_msgs::msg::JointTrajectory& joint_traj, std::vector<std::vector<float>>& traj_vec)
        {
            std::vector<float> h_vec = {
                    static_cast<float>(joint_traj.points.size()),
                    static_cast<float>(4),
                    static_cast<float>(transmission_type),
                    static_cast<float>(0)     
                };                


            traj_vec.emplace_back(h_vec);  

            for (size_t i = 0; i < joint_traj.points.size(); ++i)
            {
                const auto& point = joint_traj.points[i];

                std::vector<float> p_vec = {
                    static_cast<float>(point.positions[0]),
                    static_cast<float>(point.positions[1]),
                    static_cast<float>(point.positions[2]),
                    static_cast<float>(point.positions[3]),     
                };  

                traj_vec.emplace_back(p_vec);    
            }     
        }
    
    private:
        moveit::planning_interface::MoveGroupInterfacePtr _arm_group;
        ArmMoveStates current_state = arm_idle;
        TransmitStates transmission_type = TransmitStates::ArmMoving;
        bool activated = false;

};

#endif