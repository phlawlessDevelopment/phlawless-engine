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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/phalyce/dev/cpp_/sfml/engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phalyce/dev/cpp_/sfml/engine/build

# Include any dependencies generated for this target.
include CMakeFiles/PhlawlessEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PhlawlessEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PhlawlessEngine.dir/flags.make

CMakeFiles/PhlawlessEngine.dir/main.cpp.o: CMakeFiles/PhlawlessEngine.dir/flags.make
CMakeFiles/PhlawlessEngine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phalyce/dev/cpp_/sfml/engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PhlawlessEngine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PhlawlessEngine.dir/main.cpp.o -c /home/phalyce/dev/cpp_/sfml/engine/main.cpp

CMakeFiles/PhlawlessEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PhlawlessEngine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/phalyce/dev/cpp_/sfml/engine/main.cpp > CMakeFiles/PhlawlessEngine.dir/main.cpp.i

CMakeFiles/PhlawlessEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PhlawlessEngine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/phalyce/dev/cpp_/sfml/engine/main.cpp -o CMakeFiles/PhlawlessEngine.dir/main.cpp.s

# Object files for target PhlawlessEngine
PhlawlessEngine_OBJECTS = \
"CMakeFiles/PhlawlessEngine.dir/main.cpp.o"

# External object files for target PhlawlessEngine
PhlawlessEngine_EXTERNAL_OBJECTS =

PhlawlessEngine: CMakeFiles/PhlawlessEngine.dir/main.cpp.o
PhlawlessEngine: CMakeFiles/PhlawlessEngine.dir/build.make
PhlawlessEngine: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
PhlawlessEngine: /usr/lib/x86_64-linux-gnu/libsfml-network.so.2.5.1
PhlawlessEngine: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
PhlawlessEngine: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
PhlawlessEngine: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
PhlawlessEngine: CMakeFiles/PhlawlessEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phalyce/dev/cpp_/sfml/engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PhlawlessEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PhlawlessEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PhlawlessEngine.dir/build: PhlawlessEngine

.PHONY : CMakeFiles/PhlawlessEngine.dir/build

CMakeFiles/PhlawlessEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PhlawlessEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PhlawlessEngine.dir/clean

CMakeFiles/PhlawlessEngine.dir/depend:
	cd /home/phalyce/dev/cpp_/sfml/engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phalyce/dev/cpp_/sfml/engine /home/phalyce/dev/cpp_/sfml/engine /home/phalyce/dev/cpp_/sfml/engine/build /home/phalyce/dev/cpp_/sfml/engine/build /home/phalyce/dev/cpp_/sfml/engine/build/CMakeFiles/PhlawlessEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PhlawlessEngine.dir/depend
