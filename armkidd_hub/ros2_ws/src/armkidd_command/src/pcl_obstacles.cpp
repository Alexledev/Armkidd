#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

#include <geometry_msgs/msg/polygon_stamped.hpp>
#include <geometry_msgs/msg/point32.hpp>

#include <pcl/common/common.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/segmentation/extract_clusters.h>

#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2_eigen/tf2_eigen.hpp>

#include <std_msgs/msg/string.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>

class ObstacleSegmentationNode : public rclcpp::Node
{
public:
    ObstacleSegmentationNode() : Node("pointcloud_obstacle_segmentation")
    {
        auto qos = rclcpp::SensorDataQoS().keep_last(1);;
        pclSub = this->create_subscription<sensor_msgs::msg::PointCloud2>("/scaled_pointcloud", qos, std::bind(&ObstacleSegmentationNode::cloudCallback, this, std::placeholders::_1));
        cmdSub = this->create_subscription<std_msgs::msg::String>("/cmd_display_obstacles", 10, std::bind(&ObstacleSegmentationNode::cmdCallback, this, std::placeholders::_1));
        markerPub = this->create_publisher<visualization_msgs::msg::MarkerArray>("/object_boxes", 10);

        tfBuffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        tfListener = std::make_shared<tf2_ros::TransformListener>(*tfBuffer);
    }

private:

    void cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
    {
        currentPCL = msg;
    }
        

    void cmdCallback(const std_msgs::msg::String::SharedPtr msg)
    {      

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::fromROSMsg(*currentPCL, *cloud);

        if (cloud->empty()) return;

        std::string s = msg->data;

        std::stringstream ss(s);
        std::string token;

        float x, y;

        std::getline(ss, token, ';');
        x = std::stof(token);

        std::getline(ss, token, ';');
        y = std::stof(token);


        pcl::SACSegmentation<pcl::PointXYZ> seg;
        pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
        pcl::ModelCoefficients::Ptr coeff(new pcl::ModelCoefficients);

        seg.setOptimizeCoefficients(true);
        seg.setModelType(pcl::SACMODEL_PLANE);
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setDistanceThreshold(0.02);
        seg.setInputCloud(cloud);
        seg.segment(*inliers, *coeff);

        pcl::ExtractIndices<pcl::PointXYZ> extract;
        extract.setInputCloud(cloud);
        extract.setIndices(inliers);
        extract.setNegative(true);

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloudObjects(new pcl::PointCloud<pcl::PointXYZ>);
        extract.filter(*cloudObjects);

        // --------------------------

        pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
        tree->setInputCloud(cloudObjects);

        std::vector<pcl::PointIndices> clusters;

        pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
        ec.setClusterTolerance(0.02);     // adjust
        ec.setMinClusterSize(1000);
        ec.setMaxClusterSize(6000);
        ec.setSearchMethod(tree);
        ec.setInputCloud(cloudObjects);
        ec.extract(clusters);

        // --------------------------


        std::vector<std::string> remove_ids;

        for (int i = 0; i < 10; i++) 
        {
            remove_ids.push_back("obstacle_" + std::to_string(i));
        }

        planningSceneInterface.removeCollisionObjects(remove_ids);

       
        int id = 0;

        for (const auto &cluster : clusters)
        {
            MakeBoxes(cluster, cloudObjects, currentPCL, id, x, y);
        }
    }

    void MakeBoxes(const pcl::PointIndices &cluster, std::shared_ptr<pcl::PointCloud<pcl::PointXYZ>> &cloudObjects, 
                   const std::shared_ptr<sensor_msgs::msg::PointCloud2> &msg, int &id, float ex_x, float ex_y)
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr clusterCloud(new pcl::PointCloud<pcl::PointXYZ>);

        for (auto idx : cluster.indices)
            clusterCloud->points.push_back(cloudObjects->points[idx]);

            
        pcl::PointXYZ min_pt, max_pt;
        pcl::getMinMax3D(*clusterCloud, min_pt, max_pt);

        double height = max_pt.y - min_pt.y;
        double x = (min_pt.x + max_pt.x) / 2.0;

        if (height <= 0.35)
            return;

        
        if (x <= -0.8 || x > 1.0)   
            return;


        moveit_msgs::msg::CollisionObject collision;

        collision.header = msg->header;
        collision.id = "obstacle_" + std::to_string(id++);

        shape_msgs::msg::SolidPrimitive primitive;
        primitive.type = primitive.BOX;

        primitive.dimensions.resize(3);
        primitive.dimensions[0] = (max_pt.x - min_pt.x)/2.0;
        primitive.dimensions[1] = (max_pt.y - min_pt.y)*1.25f;
        primitive.dimensions[2] = (max_pt.z - min_pt.z)/2.0;

        geometry_msgs::msg::Pose pose;

        pose.position.x = (min_pt.x + max_pt.x) / 2.0;
        pose.position.y = (min_pt.y + max_pt.y) / 2.0;
        pose.position.z = (min_pt.z + max_pt.z) / 2.0;

        tf2::Quaternion q;
        q.setRPY(28.0 * M_PI / 180.0, 0.0, 0.0);
        pose.orientation = tf2::toMsg(q);

        geometry_msgs::msg::PoseStamped pose_cloud;
        pose_cloud.header = msg->header;
        pose_cloud.pose = pose;

        geometry_msgs::msg::PoseStamped pose_base;
        try
        {
            pose_base = tfBuffer->transform(pose_cloud, "base_link", tf2::durationFromSec(0.1));
        }
        catch (tf2::TransformException &ex)
        {
            RCLCPP_WARN(this->get_logger(), "TF failed: %s", ex.what());
            return;
        }

        double dx = pose_base.pose.position.x - ex_x;
        double dy = pose_base.pose.position.y - ex_y;

        RCLCPP_INFO(this->get_logger(), "x: %.3f - %.3f | y: %.3f - %.3f", pose_base.pose.position.x, ex_x,  pose_base.pose.position.y, ex_y);

        if (std::sqrt(dx*dx + dy*dy) < 0.45)
        {
            RCLCPP_INFO(this->get_logger(), "Target object detected");
            return;
        }


        collision.primitives.push_back(primitive);
        collision.primitive_poses.push_back(pose);
        collision.operation = collision.ADD;

        planningSceneInterface.applyCollisionObject(collision);       

    }

    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr pclSub;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr cmdSub;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr markerPub;

    std::unique_ptr<tf2_ros::Buffer> tfBuffer;
    std::shared_ptr<tf2_ros::TransformListener> tfListener;
    moveit::planning_interface::PlanningSceneInterface planningSceneInterface;

    sensor_msgs::msg::PointCloud2::SharedPtr currentPCL;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ObstacleSegmentationNode>());
    rclcpp::shutdown();
}



// Marker ver. 


// visualization_msgs::msg::Marker marker;

// marker.header = msg->header;
// marker.ns = "objects";
// marker.id = id++;
// marker.type = visualization_msgs::msg::Marker::CUBE;
// marker.action = visualization_msgs::msg::Marker::ADD;

// marker.pose.position.x = x;
// marker.pose.position.y = (min_pt.y + max_pt.y) / 2.0;
// marker.pose.position.z = (min_pt.z + max_pt.z) / 2.0;

// RCLCPP_INFO(this->get_logger(),
//     "Marker center -> x: %.3f  y: %.3f  z: %.3f",
//     marker.pose.position.x,
//     marker.pose.position.y,
//     marker.pose.position.z);

// tf2::Quaternion q;
// q.setRPY(28.0 * M_PI / 180.0, 0.0, 0.0);   // rotate around Y axis

// marker.pose.orientation = tf2::toMsg(q);

// marker.scale.x = max_pt.x - min_pt.x;
// marker.scale.y = max_pt.y - min_pt.y;
// marker.scale.z = max_pt.z - min_pt.z;

// marker.color.r = 0.0;
// marker.color.g = 1.0;
// marker.color.b = 0.0;
// marker.color.a = 0.5;


// marker.lifetime = rclcpp::Duration(0,0);

// markerArray.markers.push_back(marker);