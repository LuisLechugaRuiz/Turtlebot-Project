# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;rospy;nodelet;pluginlib;message_filters;actionlib;kdl_conversions;ecl_threads;ecl_geometry;ecl_linear_algebra;kobuki_msgs;kobuki_dock_drive;nav_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lkobuki_auto_docking_ros;-lkobuki_auto_docking_nodelet".split(';') if "-lkobuki_auto_docking_ros;-lkobuki_auto_docking_nodelet" != "" else []
PROJECT_NAME = "kobuki_auto_docking"
PROJECT_SPACE_DIR = "/home/luis/Turtlebot-Project/install"
PROJECT_VERSION = "0.7.6"
