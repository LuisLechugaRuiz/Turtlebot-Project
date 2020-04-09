cmake_minimum_required(VERSION 2.8.3)
project(costmap_restrictor)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  turtlebot_2dnav
  message_generation
)

find_package(Boost REQUIRED COMPONENTS system)

 SET(SRCS
        src/costmap_restrictor_main.cpp
        src/costmap_restrictor.cpp)

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs message_runtime turtlebot_2dnav)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(costmap_restrictor ${SRCS})

add_dependencies(costmap_restrictor decision_maker_gencpp)

target_link_libraries(costmap_restrictor
   ${catkin_LIBRARIES}
 )
