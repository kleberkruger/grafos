# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/graph_apps.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graph_apps.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph_apps.dir/flags.make

CMakeFiles/graph_apps.dir/src/core/graph.cpp.o: CMakeFiles/graph_apps.dir/flags.make
CMakeFiles/graph_apps.dir/src/core/graph.cpp.o: ../src/core/graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph_apps.dir/src/core/graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graph_apps.dir/src/core/graph.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/src/core/graph.cpp"

CMakeFiles/graph_apps.dir/src/core/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph_apps.dir/src/core/graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/src/core/graph.cpp" > CMakeFiles/graph_apps.dir/src/core/graph.cpp.i

CMakeFiles/graph_apps.dir/src/core/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph_apps.dir/src/core/graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/src/core/graph.cpp" -o CMakeFiles/graph_apps.dir/src/core/graph.cpp.s

CMakeFiles/graph_apps.dir/src/main.cpp.o: CMakeFiles/graph_apps.dir/flags.make
CMakeFiles/graph_apps.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graph_apps.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graph_apps.dir/src/main.cpp.o -c "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/src/main.cpp"

CMakeFiles/graph_apps.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph_apps.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/src/main.cpp" > CMakeFiles/graph_apps.dir/src/main.cpp.i

CMakeFiles/graph_apps.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph_apps.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/src/main.cpp" -o CMakeFiles/graph_apps.dir/src/main.cpp.s

# Object files for target graph_apps
graph_apps_OBJECTS = \
"CMakeFiles/graph_apps.dir/src/core/graph.cpp.o" \
"CMakeFiles/graph_apps.dir/src/main.cpp.o"

# External object files for target graph_apps
graph_apps_EXTERNAL_OBJECTS =

graph_apps: CMakeFiles/graph_apps.dir/src/core/graph.cpp.o
graph_apps: CMakeFiles/graph_apps.dir/src/main.cpp.o
graph_apps: CMakeFiles/graph_apps.dir/build.make
graph_apps: CMakeFiles/graph_apps.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graph_apps"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graph_apps.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph_apps.dir/build: graph_apps

.PHONY : CMakeFiles/graph_apps.dir/build

CMakeFiles/graph_apps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graph_apps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graph_apps.dir/clean

CMakeFiles/graph_apps.dir/depend:
	cd "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug" "/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos/implementações/C++/graph-apps/cmake-build-debug/CMakeFiles/graph_apps.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/graph_apps.dir/depend

