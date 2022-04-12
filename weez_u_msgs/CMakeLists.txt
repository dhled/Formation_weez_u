cmake_minimum_required(VERSION 3.0.2)
project(weez_u_msgs)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  std_msgs
  actionlib_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   MyPoint.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  ChangePoint.srv
)

## Generate actions in the 'action' folder
add_action_files(
  FILES
  GoToPoint.action
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
  actionlib_msgs
)

catkin_package(
  CATKIN_DEPENDS actionlib_msgs geometry_msgs message_runtime std_msgs
)
