cmake_minimum_required(VERSION 2.8.3)
project(turtlebot_2dnav)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  move_base
  std_msgs
  geometry_msgs
  message_generation
)

## Generate actions in the 'action' folder
## add_action_files(
##   FILES
## )


## Generate services in the 'srv' folder
 add_service_files(
   FILES
   fakeLaser.srv
   CarryingPerson.srv
   askNewFrontier.srv
   restrictCostmap.srv
 )

 ## Generate messages in the 'msg' folder
   add_message_files(
   FILES
   bounds_point_size.msg
   fake_bound.msg
   frontier.msg
   ROI.msg
 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   actionlib_msgs
   std_msgs
   geometry_msgs
 )

catkin_package(
  CATKIN_DEPENDS
  actionlib_msgs
  geometry_msgs
  std_msgs
  message_runtime
  move_base
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
