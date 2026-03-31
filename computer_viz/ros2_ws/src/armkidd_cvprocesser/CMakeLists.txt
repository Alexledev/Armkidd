cmake_minimum_required(VERSION 3.8)
project(armkidd_cvprocesser)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(armkidd_interfaces)
# find_package(image_transport REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# include_directories(include)
# include_directories(${EIGEN3_INCLUDE_DIR})

# add_executable(CVInferenceNode src/CVInferenceNode.cpp)
# ament_target_dependencies(CVInferenceNode rclcpp geometry_msgs std_msgs sensor_msgs image_transport vision_msgs ${Eigen_LIBRARIES})


ament_python_install_package(${PROJECT_NAME})

install(
  DIRECTORY armkidd_cvprocesser
  DESTINATION lib/
)

install(
  PROGRAMS armkidd_cvprocesser/cv_processer_node.py
  DESTINATION lib/${PROJECT_NAME}
)



ament_package()
