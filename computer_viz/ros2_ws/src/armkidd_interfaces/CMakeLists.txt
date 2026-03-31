cmake_minimum_required(VERSION 3.8)
project(armkidd_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)

find_package(Python3 COMPONENTS Development NumPy REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/WorldTarget.msg"
  "srv/MarkImg.srv"
  DEPENDENCIES sensor_msgs
)

install(
  DIRECTORY msg srv
  DESTINATION share/${PROJECT_NAME}
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()