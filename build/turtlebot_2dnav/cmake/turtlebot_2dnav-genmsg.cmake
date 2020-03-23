# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "turtlebot_2dnav: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(turtlebot_2dnav_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv" NAME_WE)
add_custom_target(_turtlebot_2dnav_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlebot_2dnav" "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv" "geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/PoseStamped:std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(turtlebot_2dnav
  "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot_2dnav
)

### Generating Module File
_generate_module_cpp(turtlebot_2dnav
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot_2dnav
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(turtlebot_2dnav_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(turtlebot_2dnav_generate_messages turtlebot_2dnav_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv" NAME_WE)
add_dependencies(turtlebot_2dnav_generate_messages_cpp _turtlebot_2dnav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot_2dnav_gencpp)
add_dependencies(turtlebot_2dnav_gencpp turtlebot_2dnav_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot_2dnav_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(turtlebot_2dnav
  "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot_2dnav
)

### Generating Module File
_generate_module_eus(turtlebot_2dnav
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot_2dnav
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(turtlebot_2dnav_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(turtlebot_2dnav_generate_messages turtlebot_2dnav_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv" NAME_WE)
add_dependencies(turtlebot_2dnav_generate_messages_eus _turtlebot_2dnav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot_2dnav_geneus)
add_dependencies(turtlebot_2dnav_geneus turtlebot_2dnav_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot_2dnav_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(turtlebot_2dnav
  "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot_2dnav
)

### Generating Module File
_generate_module_lisp(turtlebot_2dnav
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot_2dnav
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(turtlebot_2dnav_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(turtlebot_2dnav_generate_messages turtlebot_2dnav_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv" NAME_WE)
add_dependencies(turtlebot_2dnav_generate_messages_lisp _turtlebot_2dnav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot_2dnav_genlisp)
add_dependencies(turtlebot_2dnav_genlisp turtlebot_2dnav_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot_2dnav_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(turtlebot_2dnav
  "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot_2dnav
)

### Generating Module File
_generate_module_nodejs(turtlebot_2dnav
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot_2dnav
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(turtlebot_2dnav_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(turtlebot_2dnav_generate_messages turtlebot_2dnav_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv" NAME_WE)
add_dependencies(turtlebot_2dnav_generate_messages_nodejs _turtlebot_2dnav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot_2dnav_gennodejs)
add_dependencies(turtlebot_2dnav_gennodejs turtlebot_2dnav_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot_2dnav_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(turtlebot_2dnav
  "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot_2dnav
)

### Generating Module File
_generate_module_py(turtlebot_2dnav
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot_2dnav
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(turtlebot_2dnav_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(turtlebot_2dnav_generate_messages turtlebot_2dnav_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/Turtlebot-Project/src/turtlebot_2dnav/srv/returnCost.srv" NAME_WE)
add_dependencies(turtlebot_2dnav_generate_messages_py _turtlebot_2dnav_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlebot_2dnav_genpy)
add_dependencies(turtlebot_2dnav_genpy turtlebot_2dnav_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlebot_2dnav_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot_2dnav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlebot_2dnav
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(turtlebot_2dnav_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(turtlebot_2dnav_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot_2dnav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/turtlebot_2dnav
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(turtlebot_2dnav_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(turtlebot_2dnav_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot_2dnav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlebot_2dnav
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(turtlebot_2dnav_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(turtlebot_2dnav_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot_2dnav)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/turtlebot_2dnav
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(turtlebot_2dnav_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(turtlebot_2dnav_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot_2dnav)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot_2dnav\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlebot_2dnav
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(turtlebot_2dnav_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(turtlebot_2dnav_generate_messages_py geometry_msgs_generate_messages_py)
endif()
