cmake_minimum_required(VERSION 3.0.2)
project(capteur_1)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  weez_u_msgs
)
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp weez_u_msgs std_msgs
)

###########
## Build ##
###########


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(capteur_node src/capteur_node.cpp src/capteur.cpp)

target_link_libraries(capteur_node
  ${catkin_LIBRARIES}
)

add_executable(service_serveur_node src/service_serveur_node.cpp src/service_serveur.cpp)

target_link_libraries(service_serveur_node
  ${catkin_LIBRARIES}
)



#############
## Install ##
#############


## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
install(TARGETS 
  capteur_node
  service_serveur_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
  PATTERN ".svn" EXCLUDE
)
