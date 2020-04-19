# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(FATAL_ERROR "Could not find messages which '/home/luis/Turtlebot-Project/src/costmap_restrictor/msg/fake_bound.msg' depends on. Did you forget to specify generate_messages(DEPENDENCIES ...)?
Cannot locate message [Bound]: unknown package [fake_bound] on search path [{'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'costmap_restrictor': ['/home/luis/Turtlebot-Project/src/costmap_restrictor/msg']}]")
message(STATUS "costmap_restrictor: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icostmap_restrictor:/home/luis/Turtlebot-Project/src/costmap_restrictor/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(costmap_restrictor_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_cpp(costmap_restrictor
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/costmap_restrictor
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(costmap_restrictor_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(costmap_restrictor_generate_messages costmap_restrictor_generate_messages_cpp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(costmap_restrictor_gencpp)
add_dependencies(costmap_restrictor_gencpp costmap_restrictor_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_restrictor_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_eus(costmap_restrictor
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/costmap_restrictor
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(costmap_restrictor_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(costmap_restrictor_generate_messages costmap_restrictor_generate_messages_eus)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(costmap_restrictor_geneus)
add_dependencies(costmap_restrictor_geneus costmap_restrictor_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_restrictor_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_lisp(costmap_restrictor
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/costmap_restrictor
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(costmap_restrictor_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(costmap_restrictor_generate_messages costmap_restrictor_generate_messages_lisp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(costmap_restrictor_genlisp)
add_dependencies(costmap_restrictor_genlisp costmap_restrictor_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_restrictor_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_nodejs(costmap_restrictor
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/costmap_restrictor
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(costmap_restrictor_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(costmap_restrictor_generate_messages costmap_restrictor_generate_messages_nodejs)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(costmap_restrictor_gennodejs)
add_dependencies(costmap_restrictor_gennodejs costmap_restrictor_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_restrictor_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_py(costmap_restrictor
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap_restrictor
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(costmap_restrictor_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(costmap_restrictor_generate_messages costmap_restrictor_generate_messages_py)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(costmap_restrictor_genpy)
add_dependencies(costmap_restrictor_genpy costmap_restrictor_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS costmap_restrictor_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/costmap_restrictor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/costmap_restrictor
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(costmap_restrictor_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(costmap_restrictor_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/costmap_restrictor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/costmap_restrictor
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(costmap_restrictor_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(costmap_restrictor_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/costmap_restrictor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/costmap_restrictor
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(costmap_restrictor_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(costmap_restrictor_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/costmap_restrictor)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/costmap_restrictor
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(costmap_restrictor_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(costmap_restrictor_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap_restrictor)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap_restrictor\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/costmap_restrictor
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(costmap_restrictor_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(costmap_restrictor_generate_messages_py geometry_msgs_generate_messages_py)
endif()
