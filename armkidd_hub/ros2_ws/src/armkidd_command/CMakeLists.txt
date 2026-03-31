cmake_minimum_required(VERSION 3.8)
project(armkidd_command)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)

find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(cv_interfaces REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(armkidd_interfaces REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(behaviortree_cpp REQUIRED)

# add_library(config_loader
#   src/config_loader.cpp
# )


# target_link_libraries(config_loader yaml-cpp)

# add_executable(camera_tf src/camera_tf.cpp)
# ament_target_dependencies(camera_tf rclcpp tf2_ros geometry_msgs sensor_msgs)

add_executable(nuwacam_scaler src/nuwacam_scaler.cpp)
ament_target_dependencies(nuwacam_scaler rclcpp std_msgs rclcpp std_msgs pcl_ros pcl_conversions)


# add_executable(arm_coord_mover src/arm_coord_mover.cpp)
# target_include_directories(arm_coord_mover PUBLIC 
#   inc
# )
# ament_target_dependencies(arm_coord_mover rclcpp std_msgs armkidd_interfaces moveit_core moveit_ros_planning_interface visualization_msgs tf2_geometry_msgs )
# target_link_libraries(arm_coord_mover yaml-cpp)


add_executable(bt_coord_mover src/bt_coord_mover.cpp)
target_include_directories(bt_coord_mover PUBLIC 
  inc
)
ament_target_dependencies(bt_coord_mover rclcpp std_msgs armkidd_interfaces moveit_core moveit_ros_planning_interface visualization_msgs tf2_geometry_msgs )
target_link_libraries(bt_coord_mover yaml-cpp behaviortree_cpp::behaviortree_cpp)



add_executable(pcl_obstacles src/pcl_obstacles.cpp)
ament_target_dependencies(pcl_obstacles rclcpp geometry_msgs sensor_msgs visualization_msgs pcl_ros pcl_conversions  tf2_geometry_msgs  moveit_ros_planning_interface )

install(TARGETS
  nuwacam_scaler
  pcl_obstacles
  bt_coord_mover
  DESTINATION
  lib/${PROJECT_NAME}
)

install(
  DIRECTORY behavior_trees
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
