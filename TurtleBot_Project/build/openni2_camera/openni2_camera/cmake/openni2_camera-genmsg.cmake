# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "openni2_camera: 0 messages, 1 services")

set(MSG_I_FLAGS "")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(openni2_camera_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv" NAME_WE)
add_custom_target(_openni2_camera_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "openni2_camera" "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(openni2_camera
  "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/openni2_camera
)

### Generating Module File
_generate_module_cpp(openni2_camera
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/openni2_camera
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(openni2_camera_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(openni2_camera_generate_messages openni2_camera_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv" NAME_WE)
add_dependencies(openni2_camera_generate_messages_cpp _openni2_camera_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(openni2_camera_gencpp)
add_dependencies(openni2_camera_gencpp openni2_camera_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS openni2_camera_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(openni2_camera
  "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/openni2_camera
)

### Generating Module File
_generate_module_eus(openni2_camera
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/openni2_camera
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(openni2_camera_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(openni2_camera_generate_messages openni2_camera_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv" NAME_WE)
add_dependencies(openni2_camera_generate_messages_eus _openni2_camera_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(openni2_camera_geneus)
add_dependencies(openni2_camera_geneus openni2_camera_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS openni2_camera_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(openni2_camera
  "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/openni2_camera
)

### Generating Module File
_generate_module_lisp(openni2_camera
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/openni2_camera
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(openni2_camera_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(openni2_camera_generate_messages openni2_camera_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv" NAME_WE)
add_dependencies(openni2_camera_generate_messages_lisp _openni2_camera_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(openni2_camera_genlisp)
add_dependencies(openni2_camera_genlisp openni2_camera_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS openni2_camera_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(openni2_camera
  "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/openni2_camera
)

### Generating Module File
_generate_module_nodejs(openni2_camera
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/openni2_camera
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(openni2_camera_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(openni2_camera_generate_messages openni2_camera_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv" NAME_WE)
add_dependencies(openni2_camera_generate_messages_nodejs _openni2_camera_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(openni2_camera_gennodejs)
add_dependencies(openni2_camera_gennodejs openni2_camera_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS openni2_camera_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(openni2_camera
  "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/openni2_camera
)

### Generating Module File
_generate_module_py(openni2_camera
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/openni2_camera
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(openni2_camera_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(openni2_camera_generate_messages openni2_camera_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/luis/TurtleBot_Project/src/openni2_camera/openni2_camera/srv/GetSerial.srv" NAME_WE)
add_dependencies(openni2_camera_generate_messages_py _openni2_camera_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(openni2_camera_genpy)
add_dependencies(openni2_camera_genpy openni2_camera_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS openni2_camera_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/openni2_camera)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/openni2_camera
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/openni2_camera)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/openni2_camera
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/openni2_camera)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/openni2_camera
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/openni2_camera)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/openni2_camera
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/openni2_camera)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/openni2_camera\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/openni2_camera
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
