# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/timmytruong/Desktop/syde 1a/121/lab02_1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab02_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab02_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab02_1.dir/flags.make

CMakeFiles/lab02_1.dir/main.cpp.o: CMakeFiles/lab02_1.dir/flags.make
CMakeFiles/lab02_1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/timmytruong/Desktop/syde 1a/121/lab02_1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab02_1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab02_1.dir/main.cpp.o -c "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/main.cpp"

CMakeFiles/lab02_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab02_1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/main.cpp" > CMakeFiles/lab02_1.dir/main.cpp.i

CMakeFiles/lab02_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab02_1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/main.cpp" -o CMakeFiles/lab02_1.dir/main.cpp.s

# Object files for target lab02_1
lab02_1_OBJECTS = \
"CMakeFiles/lab02_1.dir/main.cpp.o"

# External object files for target lab02_1
lab02_1_EXTERNAL_OBJECTS =

lab02_1: CMakeFiles/lab02_1.dir/main.cpp.o
lab02_1: CMakeFiles/lab02_1.dir/build.make
lab02_1: CMakeFiles/lab02_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/timmytruong/Desktop/syde 1a/121/lab02_1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab02_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab02_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab02_1.dir/build: lab02_1

.PHONY : CMakeFiles/lab02_1.dir/build

CMakeFiles/lab02_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab02_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab02_1.dir/clean

CMakeFiles/lab02_1.dir/depend:
	cd "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/timmytruong/Desktop/syde 1a/121/lab02_1" "/Users/timmytruong/Desktop/syde 1a/121/lab02_1" "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/cmake-build-debug" "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/cmake-build-debug" "/Users/timmytruong/Desktop/syde 1a/121/lab02_1/cmake-build-debug/CMakeFiles/lab02_1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab02_1.dir/depend

