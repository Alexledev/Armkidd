#ifndef ARMKIDD_INTERFACE_H
#define ARMKIDD_INTERFACE_H

#include <rclcpp/rclcpp.hpp>
#include <hardware_interface/system_interface.hpp>
#include <rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp>
#include <rclcpp_lifecycle/state.hpp>
#include <libserial/SerialPort.h>

#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/robot_state/robot_state.hpp>

#include <moveit/planning_scene_monitor/current_state_monitor.hpp>
#include <moveit/robot_model_loader/robot_model_loader.hpp>
#include <moveit_msgs/msg/display_trajectory.hpp>
#include <std_srvs/srv/empty.hpp>
#include <std_msgs/msg/string.hpp>

#include <vector>
#include <string>
#include "serial_transfer.h"
#include "arm_control.hpp"
#include "utils.h"

namespace armkidd_controller
{
    using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;
    class ArmkiddInterface : public hardware_interface::SystemInterface
    {
        public:
            ArmkiddInterface();
            virtual ~ArmkiddInterface();

            virtual CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override;
            virtual CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

            virtual CallbackReturn on_init(const hardware_interface::HardwareInfo & hardware_info) override;
            virtual std::vector<hardware_interface::StateInterface> export_state_interfaces() override;
            virtual std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

            virtual hardware_interface::return_type read(const rclcpp::Time & time, const rclcpp::Duration & period) override;
            virtual hardware_interface::return_type write(const rclcpp::Time & time, const rclcpp::Duration & period) override;

            virtual bool isArmGoalReached();
            virtual void pathReceivedCallback(const moveit_msgs::msg::DisplayTrajectory::SharedPtr msg);
            // virtual void graspingCallback(const std::shared_ptr<std_srvs::srv::Empty::Request> request,
            //                                     std::shared_ptr<std_srvs::srv::Empty::Response> response);

            
        private:
            // LibSerial::SerialPort arduino;
            // std::string port;

            std::string port = "/dev/ttyUSB0";
            SerialTransfer serialT;
            std::shared_ptr<Arm_Control> arm_control;
            std::shared_ptr<rclcpp::Node> node;

            std::vector<double> position_commands;
            std::vector<double> prev_position_commands;
            std::vector<double> position_states;

            trajectory_msgs::msg::JointTrajectoryPoint last_pt;
            std::shared_ptr<rclcpp::executors::MultiThreadedExecutor> executor;
            rclcpp::Subscription<moveit_msgs::msg::DisplayTrajectory>::SharedPtr plan_subscription;
            rclcpp::Publisher<std_msgs::msg::String>::SharedPtr grasping_send;
            // rclcpp::Service<std_srvs::srv::Empty>::SharedPtr grasping_service;
    };
};


#endif