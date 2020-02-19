# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;nodelet;pluginlib;std_msgs;kobuki_msgs;yocs_controllers".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lbump_blink_controller_nodelet".split(';') if "-lbump_blink_controller_nodelet" != "" else []
PROJECT_NAME = "kobuki_controller_tutorial"
PROJECT_SPACE_DIR = "/home/luis/TurtleBot_Project/install"
PROJECT_VERSION = "0.7.6"
