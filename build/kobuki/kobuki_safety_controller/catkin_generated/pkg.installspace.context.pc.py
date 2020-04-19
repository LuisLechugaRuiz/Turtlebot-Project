# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;nodelet;pluginlib;std_msgs;geometry_msgs;kobuki_msgs;yocs_controllers;ecl_threads".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lkobuki_safety_controller_nodelet".split(';') if "-lkobuki_safety_controller_nodelet" != "" else []
PROJECT_NAME = "kobuki_safety_controller"
PROJECT_SPACE_DIR = "/home/luis/Turtlebot-Project/install"
PROJECT_VERSION = "0.7.6"
