# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luis/Turtlebot-Project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/Turtlebot-Project/build

# Utility rule file for poi_database_generate_messages_cpp.

# Include the progress variables for this target.
include poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/progress.make

poi_database/CMakeFiles/poi_database_generate_messages_cpp: /home/luis/Turtlebot-Project/devel/include/poi_database/ROI.h


/home/luis/Turtlebot-Project/devel/include/poi_database/ROI.h: /opt/ros/melodic/lib/gencpp/gen_cpp.py
/home/luis/Turtlebot-Project/devel/include/poi_database/ROI.h: /home/luis/Turtlebot-Project/src/poi_database/msg/ROI.msg
/home/luis/Turtlebot-Project/devel/include/poi_database/ROI.h: /opt/ros/melodic/share/geometry_msgs/msg/Point.msg
/home/luis/Turtlebot-Project/devel/include/poi_database/ROI.h: /opt/ros/melodic/share/std_msgs/msg/Header.msg
/home/luis/Turtlebot-Project/devel/include/poi_database/ROI.h: /opt/ros/melodic/share/gencpp/msg.h.template
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/luis/Turtlebot-Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating C++ code from poi_database/ROI.msg"
	cd /home/luis/Turtlebot-Project/src/poi_database && /home/luis/Turtlebot-Project/build/catkin_generated/env_cached.sh /usr/bin/python2 /opt/ros/melodic/share/gencpp/cmake/../../../lib/gencpp/gen_cpp.py /home/luis/Turtlebot-Project/src/poi_database/msg/ROI.msg -Ipoi_database:/home/luis/Turtlebot-Project/src/poi_database/msg -Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg -Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg -p poi_database -o /home/luis/Turtlebot-Project/devel/include/poi_database -e /opt/ros/melodic/share/gencpp/cmake/..

poi_database_generate_messages_cpp: poi_database/CMakeFiles/poi_database_generate_messages_cpp
poi_database_generate_messages_cpp: /home/luis/Turtlebot-Project/devel/include/poi_database/ROI.h
poi_database_generate_messages_cpp: poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/build.make

.PHONY : poi_database_generate_messages_cpp

# Rule to build all files generated by this target.
poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/build: poi_database_generate_messages_cpp

.PHONY : poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/build

poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/clean:
	cd /home/luis/Turtlebot-Project/build/poi_database && $(CMAKE_COMMAND) -P CMakeFiles/poi_database_generate_messages_cpp.dir/cmake_clean.cmake
.PHONY : poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/clean

poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/depend:
	cd /home/luis/Turtlebot-Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/Turtlebot-Project/src /home/luis/Turtlebot-Project/src/poi_database /home/luis/Turtlebot-Project/build /home/luis/Turtlebot-Project/build/poi_database /home/luis/Turtlebot-Project/build/poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : poi_database/CMakeFiles/poi_database_generate_messages_cpp.dir/depend

