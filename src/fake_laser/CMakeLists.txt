cmake_minimum_required(VERSION 2.8.3)
project(fake_laser)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  turtlebot_2dnav
  pcl_ros
  tf
)

find_package(Boost REQUIRED COMPONENTS system)

 SET(SRCS
        src/fake_laser_main.cpp
        src/fake_laser.cpp)

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs message_runtime turtlebot_2dnav
                 pcl_ros tf)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(fake_laser ${SRCS})

add_dependencies(fake_laser decision_maker_gencpp)

target_link_libraries(fake_laser
   ${catkin_LIBRARIES}
 )
