# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/lieu/dev/code-gl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lieu/dev/code-gl

# Include any dependencies generated for this target.
include CMakeFiles/CodeGUI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CodeGUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CodeGUI.dir/flags.make

CMakeFiles/CodeGUI.dir/sdlMain.cpp.o: CMakeFiles/CodeGUI.dir/flags.make
CMakeFiles/CodeGUI.dir/sdlMain.cpp.o: sdlMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lieu/dev/code-gl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CodeGUI.dir/sdlMain.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeGUI.dir/sdlMain.cpp.o -c /home/lieu/dev/code-gl/sdlMain.cpp

CMakeFiles/CodeGUI.dir/sdlMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeGUI.dir/sdlMain.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lieu/dev/code-gl/sdlMain.cpp > CMakeFiles/CodeGUI.dir/sdlMain.cpp.i

CMakeFiles/CodeGUI.dir/sdlMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeGUI.dir/sdlMain.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lieu/dev/code-gl/sdlMain.cpp -o CMakeFiles/CodeGUI.dir/sdlMain.cpp.s

CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.requires:

.PHONY : CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.requires

CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.provides: CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.requires
	$(MAKE) -f CMakeFiles/CodeGUI.dir/build.make CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.provides.build
.PHONY : CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.provides

CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.provides.build: CMakeFiles/CodeGUI.dir/sdlMain.cpp.o


CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o: CMakeFiles/CodeGUI.dir/flags.make
CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o: sdl/SDLWindowManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lieu/dev/code-gl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o -c /home/lieu/dev/code-gl/sdl/SDLWindowManager.cpp

CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lieu/dev/code-gl/sdl/SDLWindowManager.cpp > CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.i

CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lieu/dev/code-gl/sdl/SDLWindowManager.cpp -o CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.s

CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.requires:

.PHONY : CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.requires

CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.provides: CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/CodeGUI.dir/build.make CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.provides.build
.PHONY : CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.provides

CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.provides.build: CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o


CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o: CMakeFiles/CodeGUI.dir/flags.make
CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o: sdl/TextField.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lieu/dev/code-gl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o -c /home/lieu/dev/code-gl/sdl/TextField.cpp

CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lieu/dev/code-gl/sdl/TextField.cpp > CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.i

CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lieu/dev/code-gl/sdl/TextField.cpp -o CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.s

CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.requires:

.PHONY : CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.requires

CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.provides: CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.requires
	$(MAKE) -f CMakeFiles/CodeGUI.dir/build.make CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.provides.build
.PHONY : CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.provides

CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.provides.build: CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o


# Object files for target CodeGUI
CodeGUI_OBJECTS = \
"CMakeFiles/CodeGUI.dir/sdlMain.cpp.o" \
"CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o" \
"CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o"

# External object files for target CodeGUI
CodeGUI_EXTERNAL_OBJECTS =

CodeGUI: CMakeFiles/CodeGUI.dir/sdlMain.cpp.o
CodeGUI: CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o
CodeGUI: CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o
CodeGUI: CMakeFiles/CodeGUI.dir/build.make
CodeGUI: CMakeFiles/CodeGUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lieu/dev/code-gl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CodeGUI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CodeGUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CodeGUI.dir/build: CodeGUI

.PHONY : CMakeFiles/CodeGUI.dir/build

CMakeFiles/CodeGUI.dir/requires: CMakeFiles/CodeGUI.dir/sdlMain.cpp.o.requires
CMakeFiles/CodeGUI.dir/requires: CMakeFiles/CodeGUI.dir/sdl/SDLWindowManager.cpp.o.requires
CMakeFiles/CodeGUI.dir/requires: CMakeFiles/CodeGUI.dir/sdl/TextField.cpp.o.requires

.PHONY : CMakeFiles/CodeGUI.dir/requires

CMakeFiles/CodeGUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CodeGUI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CodeGUI.dir/clean

CMakeFiles/CodeGUI.dir/depend:
	cd /home/lieu/dev/code-gl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lieu/dev/code-gl /home/lieu/dev/code-gl /home/lieu/dev/code-gl /home/lieu/dev/code-gl /home/lieu/dev/code-gl/CMakeFiles/CodeGUI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CodeGUI.dir/depend

