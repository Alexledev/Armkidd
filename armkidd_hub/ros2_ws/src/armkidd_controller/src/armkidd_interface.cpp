#include "../include/armkidd_controller/armkidd_interface.hpp"
#include <hardware_interface/types/hardware_interface_return_values.hpp>
#include <pluginlib/class_list_macros.hpp>

namespace armkidd_controller
{   

    ArmkiddInterface::ArmkiddInterface()
    {
        node = rclcpp::Node::make_shared("my_planner");
    }

    ArmkiddInterface::~ArmkiddInterface()
    {
        serialT.close();
    }

    CallbackReturn ArmkiddInterface::on_init(const hardware_interface::HardwareInfo & hardware_info)
    {
        CallbackReturn result = hardware_interface::SystemInterface::on_init(hardware_info);

        if (result != CallbackReturn::SUCCESS)
        {
            return result;
        }
       
        try
        {
            port =  info_.hardware_parameters.at("port");
            serialT.open(port, LibSerial::BaudRate::BAUD_115200);


            std::shared_ptr<moveit::planning_interface::MoveGroupInterface> mgI = std::make_shared<moveit::planning_interface::MoveGroupInterface>(node, "arm");
           
            arm_control = std::make_shared<Arm_Control>(mgI);

            plan_subscription = node->create_subscription<moveit_msgs::msg::DisplayTrajectory>("/display_planned_path", 10, std::bind(&ArmkiddInterface::pathReceivedCallback, this, std::placeholders::_1));

            grasping_send = node->create_publisher<std_msgs::msg::String>("grasping_call", 10); 


            executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
            executor->add_node(node);


        }
        catch (const std::out_of_range &e)
        {
            RCLCPP_FATAL(rclcpp::get_logger("ArmkiddInterface"), "No Serial Port provided! Aborting");
            return CallbackReturn::FAILURE;
        }

        position_commands.resize(info_.joints.size());
        position_states.resize(info_.joints.size());
        prev_position_commands.resize(info_.joints.size());

        return CallbackReturn::SUCCESS;
    }

    std::vector<hardware_interface::StateInterface> ArmkiddInterface::export_state_interfaces()
    {
        std::vector<hardware_interface::StateInterface> state_interfaces;
        RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Export_state_interfaces...");

        for (size_t i = 0; i < info_.joints.size(); i ++)
        {
            state_interfaces.emplace_back(hardware_interface::StateInterface(info_.joints[i].name, hardware_interface::HW_IF_POSITION, &position_states[i]));
        }

        return state_interfaces;
    }

    std::vector<hardware_interface::CommandInterface> ArmkiddInterface::export_command_interfaces()
    {
        std::vector<hardware_interface::CommandInterface> command_interface;
        RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Export_command_interfaces...");

        for (size_t i = 0; i < info_.joints.size(); i++)
        {
            command_interface.emplace_back(hardware_interface::CommandInterface(info_.joints[i].name, hardware_interface::HW_IF_POSITION, &position_commands[i]));
        }

        return command_interface;
    }

    CallbackReturn ArmkiddInterface::on_activate(const rclcpp_lifecycle::State & previous_state)
    {
        RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Starting the robot hardware...");

        std::vector<double> rest_positions = {
            0.0,         // joint_1
            -1.3,       // joint_2  (≈-74°)
            1.3,        // joint_3  (≈74°)
            0.43,        // joint_4 (≈42°),
            0,        // joint_5
            0.04        // joint_6
        };

        position_commands = rest_positions;
        prev_position_commands = rest_positions;
        position_states = rest_positions;

        return CallbackReturn::SUCCESS;
    }

    CallbackReturn ArmkiddInterface::on_deactivate(const rclcpp_lifecycle::State & previous_state)
    {
        RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Stopping the robot hardware");
        serialT.close();
        RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Hardware stopped");
        return CallbackReturn::SUCCESS;
    }

    hardware_interface::return_type ArmkiddInterface::read(const rclcpp::Time & time, const rclcpp::Duration & period)
    {
       
        
        position_states = position_commands;

        std::string input;
        if (serialT.read_msg(input))
        {
            TransmitStates state = Utils::convertToTransmitState(input);
            arm_control->handleControl(state); 

            if (state == TransmitStates::GripperGraspComplete)
            {
                RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Send Grip msg");
                std_msgs::msg::String msg;
                msg.data = "Gripped object";
                grasping_send->publish(msg);
            }
        }
       
        executor->spin_some();

        return hardware_interface::return_type::OK;
    }

    hardware_interface::return_type ArmkiddInterface::write(const rclcpp::Time & time, const rclcpp::Duration & period) 
    {

        if (position_commands == prev_position_commands)
        {
            return hardware_interface::return_type::OK;
        }

        std::vector<float> traj_vec;

        if (isArmGoalReached())
        {           
            arm_control->parseData(position_commands, traj_vec, true);

            // RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), " -------- Goal reached! -------- ");
            // RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), 
            // "Final state: b: %.4f -> %.4f, s: %.4f -> %.4f, e: %.4f -> %.4f, w: %.4f -> %.4f, x: %.4f -> %.4f",
            // position_commands[0], last_pt.positions[0],
            // position_commands[1], last_pt.positions[1],
            // position_commands[2], last_pt.positions[2],
            // position_commands[3], last_pt.positions[3],
            // position_commands[4], last_pt.positions[4]);     
        }
        else
        {
            arm_control->parseData(position_commands, traj_vec, false);

            // RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), 
            // "b: %.4f -> %.4f, s: %.4f -> %.4f, e: %.4f -> %.4f, w: %.4f -> %.4f, x: %.4f -> %.4f",
            // position_commands[0], last_pt.positions[0],
            // position_commands[1], last_pt.positions[1],
            // position_commands[2], last_pt.positions[2],
            // position_commands[3], last_pt.positions[3],
            // position_commands[4], last_pt.positions[4]);         
        }


        try
        {
            serialT.write(traj_vec);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR_STREAM(rclcpp::get_logger("ArmkiddInterface"), "Something went wrong while sending the message: " << e.what());
            return hardware_interface::return_type::ERROR;
        }

        return hardware_interface::return_type::OK;
    }

    bool ArmkiddInterface::isArmGoalReached()
    {
        const double tol = 1e-3;
        for (size_t i = 0; i + 1 < position_commands.size(); ++i) // skip gripper
        {
            double error = std::fabs(position_commands[i] - last_pt.positions[i]);
            if (error > tol) {
                return false; // still moving
            }
        }
        return true;
    }


    void ArmkiddInterface::pathReceivedCallback(const moveit_msgs::msg::DisplayTrajectory::SharedPtr msg)
    {
        if (msg->trajectory.empty())
        {
            RCLCPP_INFO(rclcpp::get_logger("ArmkiddInterface"), "Received empty trajectory");
            return;
        }

        const auto& joint_traj = msg->trajectory[0].joint_trajectory;
        size_t n_points = joint_traj.points.size();

                
        last_pt = joint_traj.points.back();

    }
};


PLUGINLIB_EXPORT_CLASS(armkidd_controller::ArmkiddInterface, hardware_interface::SystemInterface);