#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <sensor_msgs/point_cloud2_iterator.hpp>

class PointCloudScaler : public rclcpp::Node
{
public:
    PointCloudScaler() : Node("pointcloud_scaler")
    {
        auto pclQos = rclcpp::QoS(rclcpp::KeepLast(1)).reliability(rclcpp::ReliabilityPolicy::Reliable).durability(rclcpp::DurabilityPolicy::Volatile);
        auto pubQos = rclcpp::SensorDataQoS().keep_last(1);

        subscription = this->create_subscription<sensor_msgs::msg::PointCloud2>("/ascamera_hp60c/camera_publisher/depth0/points", pclQos, std::bind(&PointCloudScaler::cloudCallback, this, std::placeholders::_1));
        publisher = this->create_publisher<sensor_msgs::msg::PointCloud2>("/scaled_pointcloud", pubQos);
        // publisher2 = this->create_publisher<sensor_msgs::msg::PointCloud2>("/head_camera/depth_registered/points", qos);    
    }

private:

    void cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
    {
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 5000, "cloudCallback running ");

        sensor_msgs::msg::PointCloud2 scaled_msg = *msg; // 1 copy, unavoidable unless using loaned messages

        try 
        {
            for (sensor_msgs::PointCloud2Iterator<float> x(scaled_msg, "x"), y(scaled_msg, "y"), z(scaled_msg, "z"); x != x.end(); ++x, ++y, ++z)
            {
                *x *= 10.0f;
                *y *= 10.0f;
                *z *= 10.0f;
            }
        } 
        catch (const std::exception &e) 
        {
            RCLCPP_ERROR(this->get_logger(), "Exception: %s", e.what());
        }

        publisher->publish(scaled_msg);
        // publisher2->publish(sensor_msgs::msg::PointCloud2(scaled_msg));
        // publisher2->publish(scaled_msg);
    }

    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr publisher;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr publisher2;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PointCloudScaler>();
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();

    return 0;
}