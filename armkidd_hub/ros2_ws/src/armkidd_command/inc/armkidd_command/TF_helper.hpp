#pragma once

#include <rclcpp/rclcpp.hpp>
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

#include "geometry_msgs/msg/point_stamped.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <visualization_msgs/msg/marker.hpp>

class TFHelper
{
public:
    TFHelper(const rclcpp::Node::SharedPtr targetNode) 
    {
        this->targetNode = targetNode;
        markerPub = this->targetNode->create_publisher<visualization_msgs::msg::Marker>("visualized_marker", 10);
    }

    void setPointParams(float cameraAngle, float xOffsetScale, float yOffsetScale, float zOffsetScale)
    {
        this->cameraAngle = cameraAngle;
        this->xOffsetScale = xOffsetScale;
        this->yOffsetScale = yOffsetScale;
        this->zOffsetScale = zOffsetScale;
    }

    void setTFFrames(std::shared_ptr<tf2_ros::Buffer> tfBuffer, std::string baseFrame, std::string cameraFrame)
    {
        this->tfBuffer = tfBuffer;
        this->baseFrame = baseFrame;
        this->cameraFrame = cameraFrame;
    }

    void convertCamToReal(geometry_msgs::msg::PointStamped& realPoint, float x, float y, float z) {
        realPoint.point.x = z;
        realPoint.point.y = x; 
        realPoint.point.z = -y;
    }

    geometry_msgs::msg::PointStamped getPoint(float x, float y, float z, float width, float height, bool& valid) {

        geometry_msgs::msg::PointStamped pointBefore;
        pointBefore.header.frame_id = "camera_head_link";
        pointBefore.header.stamp = rclcpp::Time(0);

        // Camera coords (forward z, up y, right x) to Arm coords (forward x, up z, left y)
        convertCamToReal(pointBefore, x, y, z);

        geometry_msgs::msg::PointStamped pointBase;

        transformPointTF(pointBase, pointBefore);

        pointBase.point.x += 0.1f * xOffsetScale;
        pointBase.point.y += 0.1f * yOffsetScale;
        pointBase.point.z = height - 0.5f  * zOffsetScale + pointBase.point.x * 0.1f;

        valid = true;

        if (pointBase.point.x < 1.0f || pointBase.point.x > 4.0f)
        {
            RCLCPP_ERROR(targetNode->get_logger(), "Invalid X location lol");
            valid = false;
        }

        return pointBase;
    }
    
    void transformPointTF(geometry_msgs::msg::PointStamped &point_base, geometry_msgs::msg::PointStamped &point)
    {
        try
        {
            if (!tfBuffer->canTransform(baseFrame, point.header.frame_id, tf2::TimePointZero, tf2::durationFromSec(1.0)))
            {
                RCLCPP_WARN(targetNode->get_logger(), "Transform not yet available.");
            }

            point_base = tfBuffer->transform(point, baseFrame);
        }
        catch (tf2::TransformException &ex)
        {
            RCLCPP_WARN(targetNode->get_logger(), "TF transform failed: %s", ex.what());
        }
    }
    
    void drawMarker(geometry_msgs::msg::PointStamped &point_base, int id = 0, float r = 1.0f, float g = 0.2f, float b = 0.2f)
    {
        visualization_msgs::msg::Marker marker;
        marker.header = point_base.header;
        marker.ns = "detected_target";
        marker.id = id;
        marker.type = visualization_msgs::msg::Marker::SPHERE;
        marker.action = visualization_msgs::msg::Marker::ADD;
        marker.pose.position.x = point_base.point.x;
        marker.pose.position.y = point_base.point.y;
        marker.pose.position.z = point_base.point.z;
        marker.pose.orientation.w = 1.0;
        marker.scale.x = 0.05;
        marker.scale.y = 0.05;
        marker.scale.z = 0.05;
        marker.color.a = 1.0;
        marker.color.r = r;
        marker.color.g = g;
        marker.color.b = b;

        markerPub->publish(marker);
    }

    private:
        float cameraAngle = 28.0f * M_PI / 180.0f; //  * M_PI / 180.0f
        float xOffsetScale = 1.0;
        float yOffsetScale = 1.0;
        float zOffsetScale = 1.0;

        std::string baseFrame;
        std::string cameraFrame;

        rclcpp::Node::SharedPtr targetNode;

        std::shared_ptr<tf2_ros::Buffer> tfBuffer;
        rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr markerPub;
};

