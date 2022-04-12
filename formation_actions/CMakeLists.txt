cmake_minimum_required(VERSION 3.0.2)
project(formation_actions)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  weez_u_msgs
  actionlib
)
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp weez_u_msgs actionlib
)

###########
## Build ##
###########


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(serveur_node src/serveur_node.cpp src/serveur.cpp)

target_link_libraries(serveur_node
  ${catkin_LIBRARIES}
)

add_executable(client_node src/client_node.cpp src/client.cpp)

target_link_libraries(client_node
  ${catkin_LIBRARIES}
)



#############
## Install ##
#############


## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
install(TARGETS 
  serveur_node
  client_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
  PATTERN ".svn" EXCLUDE
)
