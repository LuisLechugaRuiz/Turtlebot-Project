# Install script for directory: /home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/luis/Turtlebot-Project/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/luis/Turtlebot-Project/build/kobuki/kobuki_testsuite/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/luis/Turtlebot-Project/build/kobuki/kobuki_testsuite/catkin_generated/installspace/kobuki_testsuite.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kobuki_testsuite/cmake" TYPE FILE FILES
    "/home/luis/Turtlebot-Project/build/kobuki/kobuki_testsuite/catkin_generated/installspace/kobuki_testsuiteConfig.cmake"
    "/home/luis/Turtlebot-Project/build/kobuki/kobuki_testsuite/catkin_generated/installspace/kobuki_testsuiteConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kobuki_testsuite" TYPE FILE FILES "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kobuki_testsuite" TYPE PROGRAM FILES
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/inf_rotation.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_analog_input.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_battery_voltage.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_events.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_gyro.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_led_array.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_rotation.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_sounds.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/scan_angle.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_battery"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_digital_output.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_external_power.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_input.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_output.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_safewandering.py"
    "/home/luis/Turtlebot-Project/src/kobuki/kobuki_testsuite/scripts/test_translation.py"
    )
endif()

