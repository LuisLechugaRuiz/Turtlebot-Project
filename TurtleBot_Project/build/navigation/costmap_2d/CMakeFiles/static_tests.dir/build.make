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
CMAKE_SOURCE_DIR = /home/luis/TurtleBot_Project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/TurtleBot_Project/build

# Include any dependencies generated for this target.
include navigation/costmap_2d/CMakeFiles/static_tests.dir/depend.make

# Include the progress variables for this target.
include navigation/costmap_2d/CMakeFiles/static_tests.dir/progress.make

# Include the compile flags for this target's objects.
include navigation/costmap_2d/CMakeFiles/static_tests.dir/flags.make

navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o: navigation/costmap_2d/CMakeFiles/static_tests.dir/flags.make
navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o: /home/luis/TurtleBot_Project/src/navigation/costmap_2d/test/static_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/TurtleBot_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o"
	cd /home/luis/TurtleBot_Project/build/navigation/costmap_2d && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/static_tests.dir/test/static_tests.cpp.o -c /home/luis/TurtleBot_Project/src/navigation/costmap_2d/test/static_tests.cpp

navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static_tests.dir/test/static_tests.cpp.i"
	cd /home/luis/TurtleBot_Project/build/navigation/costmap_2d && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/TurtleBot_Project/src/navigation/costmap_2d/test/static_tests.cpp > CMakeFiles/static_tests.dir/test/static_tests.cpp.i

navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static_tests.dir/test/static_tests.cpp.s"
	cd /home/luis/TurtleBot_Project/build/navigation/costmap_2d && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/TurtleBot_Project/src/navigation/costmap_2d/test/static_tests.cpp -o CMakeFiles/static_tests.dir/test/static_tests.cpp.s

navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.requires:

.PHONY : navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.requires

navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.provides: navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.requires
	$(MAKE) -f navigation/costmap_2d/CMakeFiles/static_tests.dir/build.make navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.provides.build
.PHONY : navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.provides

navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.provides.build: navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o


# Object files for target static_tests
static_tests_OBJECTS = \
"CMakeFiles/static_tests.dir/test/static_tests.cpp.o"

# External object files for target static_tests
static_tests_EXTERNAL_OBJECTS =

/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: navigation/costmap_2d/CMakeFiles/static_tests.dir/build.make
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /home/luis/TurtleBot_Project/devel/lib/liblayers.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: gtest/googlemock/gtest/libgtest.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /home/luis/TurtleBot_Project/devel/lib/libcostmap_2d.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libdynamic_reconfigure_config_init_mutex.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/liblaser_geometry.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libclass_loader.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/libPocoFoundation.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libdl.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libroslib.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/librospack.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/liborocos-kdl.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/liborocos-kdl.so.1.4.0
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libtf2_ros.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libactionlib.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libmessage_filters.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libtf2.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /home/luis/TurtleBot_Project/devel/lib/libvoxel_grid.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libroscpp.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/librosconsole.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/librostime.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /opt/ros/melodic/lib/libcpp_common.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests: navigation/costmap_2d/CMakeFiles/static_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/TurtleBot_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests"
	cd /home/luis/TurtleBot_Project/build/navigation/costmap_2d && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/static_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
navigation/costmap_2d/CMakeFiles/static_tests.dir/build: /home/luis/TurtleBot_Project/devel/lib/costmap_2d/static_tests

.PHONY : navigation/costmap_2d/CMakeFiles/static_tests.dir/build

navigation/costmap_2d/CMakeFiles/static_tests.dir/requires: navigation/costmap_2d/CMakeFiles/static_tests.dir/test/static_tests.cpp.o.requires

.PHONY : navigation/costmap_2d/CMakeFiles/static_tests.dir/requires

navigation/costmap_2d/CMakeFiles/static_tests.dir/clean:
	cd /home/luis/TurtleBot_Project/build/navigation/costmap_2d && $(CMAKE_COMMAND) -P CMakeFiles/static_tests.dir/cmake_clean.cmake
.PHONY : navigation/costmap_2d/CMakeFiles/static_tests.dir/clean

navigation/costmap_2d/CMakeFiles/static_tests.dir/depend:
	cd /home/luis/TurtleBot_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/TurtleBot_Project/src /home/luis/TurtleBot_Project/src/navigation/costmap_2d /home/luis/TurtleBot_Project/build /home/luis/TurtleBot_Project/build/navigation/costmap_2d /home/luis/TurtleBot_Project/build/navigation/costmap_2d/CMakeFiles/static_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : navigation/costmap_2d/CMakeFiles/static_tests.dir/depend

