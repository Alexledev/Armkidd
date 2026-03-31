#pragma once

#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/string.hpp>
#include <behaviortree_cpp/bt_factory.h>

#include <armkidd_interfaces/msg/world_target.hpp>
#include <armkidd_command/TF_helper.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>

class WaitForCommand : public BT::ConditionNode
{
    public:
        WaitForCommand(const std::string& name, const BT::NodeConfiguration& config) : BT::ConditionNode(name, config) {}

        static BT::PortsList providedPorts()
        {
            return {};
        }

        BT::NodeStatus tick() override
        {
            if (!node)
                node = config().blackboard->get<rclcpp::Node::SharedPtr>("node");

            if (!tfHelper)
                tfHelper = config().blackboard->get<std::shared_ptr<TFHelper>>("tfHelper");

            armkidd_interfaces::msg::WorldTarget msg;

            if (!fetchCommand(msg))
                return BT::NodeStatus::FAILURE;

            geometry_msgs::msg::PointStamped pt;

            if (!computeTarget(msg, pt))
            {
                RCLCPP_ERROR(node->get_logger(), "Invalid target point");
                return BT::NodeStatus::FAILURE;
            }                

            publishObstacles(pt);

            tfHelper->drawMarker(pt, 0);

            config().blackboard->set("targetPoint", pt);

            return BT::NodeStatus::SUCCESS;
        }
        
    private:

        bool fetchCommand(armkidd_interfaces::msg::WorldTarget& msg)
        {
            auto msgPtr = config().blackboard->get<armkidd_interfaces::msg::WorldTarget::SharedPtr>("currentCmd");

            if (!msgPtr)
                return false;

            msg = *msgPtr;

            config().blackboard->set<armkidd_interfaces::msg::WorldTarget::SharedPtr>("currentCmd", nullptr);

            if (msg.depth == 0)
            {
                RCLCPP_WARN(node->get_logger(), "Depth invalid");
                return false;
            }

            return true;
        }

        bool computeTarget(const armkidd_interfaces::msg::WorldTarget& msg, geometry_msgs::msg::PointStamped& pt)
        {
            float x = msg.target_x * -scaleUp;
            float y = msg.target_y * scaleUp;
            float z = msg.depth * scaleUp;
            float width = msg.width * scaleUp;
            float height = msg.height * scaleUp;

            RCLCPP_WARN(node->get_logger(), "Raw values -> x: %.4f, y: %.4f, z(depth): %.4f, width: %.4f, height: %.4f.",
                        msg.target_x, msg.target_y, msg.depth, msg.width, msg.height);

            bool valid = false;

            pt = tfHelper->getPoint(x, y, z, width, height, valid);

            return valid;
        }

        void publishObstacles(const geometry_msgs::msg::PointStamped& pt)
        {
            auto obsPub = config().blackboard->get<rclcpp::Publisher<std_msgs::msg::String>::SharedPtr>("obsPub");

            std::ostringstream ss;
            ss << pt.point.x << ";" << pt.point.y << ";";

            std_msgs::msg::String msg;
            msg.data = ss.str();

            obsPub->publish(msg);
        }

        rclcpp::Node::SharedPtr node;
        std::shared_ptr<TFHelper> tfHelper;
        
        bool command_received = false;
        const float scaleUp = 10.0f; // Scale from meters to cm
};