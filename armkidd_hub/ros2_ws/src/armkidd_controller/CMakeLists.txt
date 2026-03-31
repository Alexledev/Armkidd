cmake_minimum_required(VERSION 3.8)
project(armkidd_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(hardware_interface REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)

find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

find_package(PkgConfig)
pkg_check_modules(SERIAL libserial)


add_library(${PROJECT_NAME} SHARED
  src/armkidd_interface.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE
  include
  "${SERIAL_INCLUDE_DIRS}"
)
target_link_libraries(${PROJECT_NAME}
  "${SERIAL_LDFLAGS}"
)
ament_target_dependencies(${PROJECT_NAME}
  hardware_interface
  pluginlib
  rclcpp
  rclcpp_lifecycle
  std_msgs
  moveit_core 
  moveit_ros_planning_interface
)

pluginlib_export_plugin_description_file(hardware_interface armkidd_controller.xml)


# find_package()
install(
  DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  TARGETS
  ${PROJECT_NAME}
  # slider_control  
  DESTINATION lib
)

install(
  DIRECTORY include 
  DESTINATION include
)

ament_export_include_directories(
  include
)

ament_export_libraries(
  ${PROJECT_NAME}
)

ament_export_dependencies(
  hardware_interface
  pluginlib
  rclcpp
  rclcpp_lifecycle
  std_msgs
)

ament_package()
