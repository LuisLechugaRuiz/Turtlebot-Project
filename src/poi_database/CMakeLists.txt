cmake_minimum_required(VERSION 2.8.3)
project(poi_database)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  message_generation
  ros_img_processor
)


## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   geometry_msgs
   std_msgs
 )


 SET(SRCS
        src/database_main.cpp
        src/database.cpp)


catkin_package(
   CATKIN_DEPENDS geometry_msgs roscpp std_msgs message_runtime ros_img_processor
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(database ${SRCS})

## Specify libraries to link a library or executable target against
target_link_libraries(database
   ${catkin_LIBRARIES}
 )

add_dependencies(database ros_img_processor_gencpp)
