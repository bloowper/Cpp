# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tomek/Documents/C++/myVector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomek/Documents/C++/myVector/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/myVector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myVector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myVector.dir/flags.make

CMakeFiles/myVector.dir/main.cpp.o: CMakeFiles/myVector.dir/flags.make
CMakeFiles/myVector.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomek/Documents/C++/myVector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myVector.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myVector.dir/main.cpp.o -c /home/tomek/Documents/C++/myVector/main.cpp

CMakeFiles/myVector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myVector.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomek/Documents/C++/myVector/main.cpp > CMakeFiles/myVector.dir/main.cpp.i

CMakeFiles/myVector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myVector.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomek/Documents/C++/myVector/main.cpp -o CMakeFiles/myVector.dir/main.cpp.s

CMakeFiles/myVector.dir/myVector.cpp.o: CMakeFiles/myVector.dir/flags.make
CMakeFiles/myVector.dir/myVector.cpp.o: ../myVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tomek/Documents/C++/myVector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/myVector.dir/myVector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myVector.dir/myVector.cpp.o -c /home/tomek/Documents/C++/myVector/myVector.cpp

CMakeFiles/myVector.dir/myVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myVector.dir/myVector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomek/Documents/C++/myVector/myVector.cpp > CMakeFiles/myVector.dir/myVector.cpp.i

CMakeFiles/myVector.dir/myVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myVector.dir/myVector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomek/Documents/C++/myVector/myVector.cpp -o CMakeFiles/myVector.dir/myVector.cpp.s

# Object files for target myVector
myVector_OBJECTS = \
"CMakeFiles/myVector.dir/main.cpp.o" \
"CMakeFiles/myVector.dir/myVector.cpp.o"

# External object files for target myVector
myVector_EXTERNAL_OBJECTS =

myVector: CMakeFiles/myVector.dir/main.cpp.o
myVector: CMakeFiles/myVector.dir/myVector.cpp.o
myVector: CMakeFiles/myVector.dir/build.make
myVector: CMakeFiles/myVector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tomek/Documents/C++/myVector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable myVector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myVector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myVector.dir/build: myVector

.PHONY : CMakeFiles/myVector.dir/build

CMakeFiles/myVector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myVector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myVector.dir/clean

CMakeFiles/myVector.dir/depend:
	cd /home/tomek/Documents/C++/myVector/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomek/Documents/C++/myVector /home/tomek/Documents/C++/myVector /home/tomek/Documents/C++/myVector/cmake-build-debug /home/tomek/Documents/C++/myVector/cmake-build-debug /home/tomek/Documents/C++/myVector/cmake-build-debug/CMakeFiles/myVector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myVector.dir/depend
