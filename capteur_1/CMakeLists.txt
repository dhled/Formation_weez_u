cmake_minimum_required(VERSION 3.5)
project(capteur_1)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(weez_u_msgs REQUIRED)


include_directories(include)

add_executable(capteur_node src/capteur_node.cpp src/capteur.cpp)
ament_target_dependencies(capteur_node "rclcpp" "std_msgs" "weez_u_msgs")

install(TARGETS 
  capteur_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
