# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Drax/Programming/Graphics/ppm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Drax/Programming/Graphics/ppm/build

# Include any dependencies generated for this target.
include CMakeFiles/ppm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ppm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ppm.dir/flags.make

CMakeFiles/ppm.dir/main.cpp.o: CMakeFiles/ppm.dir/flags.make
CMakeFiles/ppm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/ppm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ppm.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ppm.dir/main.cpp.o -c /Users/Drax/Programming/Graphics/ppm/main.cpp

CMakeFiles/ppm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppm.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/ppm/main.cpp > CMakeFiles/ppm.dir/main.cpp.i

CMakeFiles/ppm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppm.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/ppm/main.cpp -o CMakeFiles/ppm.dir/main.cpp.s

CMakeFiles/ppm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ppm.dir/main.cpp.o.requires

CMakeFiles/ppm.dir/main.cpp.o.provides: CMakeFiles/ppm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ppm.dir/build.make CMakeFiles/ppm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ppm.dir/main.cpp.o.provides

CMakeFiles/ppm.dir/main.cpp.o.provides.build: CMakeFiles/ppm.dir/main.cpp.o


CMakeFiles/ppm.dir/Vector2D.cpp.o: CMakeFiles/ppm.dir/flags.make
CMakeFiles/ppm.dir/Vector2D.cpp.o: ../Vector2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/ppm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ppm.dir/Vector2D.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ppm.dir/Vector2D.cpp.o -c /Users/Drax/Programming/Graphics/ppm/Vector2D.cpp

CMakeFiles/ppm.dir/Vector2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppm.dir/Vector2D.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/ppm/Vector2D.cpp > CMakeFiles/ppm.dir/Vector2D.cpp.i

CMakeFiles/ppm.dir/Vector2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppm.dir/Vector2D.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/ppm/Vector2D.cpp -o CMakeFiles/ppm.dir/Vector2D.cpp.s

CMakeFiles/ppm.dir/Vector2D.cpp.o.requires:

.PHONY : CMakeFiles/ppm.dir/Vector2D.cpp.o.requires

CMakeFiles/ppm.dir/Vector2D.cpp.o.provides: CMakeFiles/ppm.dir/Vector2D.cpp.o.requires
	$(MAKE) -f CMakeFiles/ppm.dir/build.make CMakeFiles/ppm.dir/Vector2D.cpp.o.provides.build
.PHONY : CMakeFiles/ppm.dir/Vector2D.cpp.o.provides

CMakeFiles/ppm.dir/Vector2D.cpp.o.provides.build: CMakeFiles/ppm.dir/Vector2D.cpp.o


CMakeFiles/ppm.dir/Vector3D.cpp.o: CMakeFiles/ppm.dir/flags.make
CMakeFiles/ppm.dir/Vector3D.cpp.o: ../Vector3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/ppm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ppm.dir/Vector3D.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ppm.dir/Vector3D.cpp.o -c /Users/Drax/Programming/Graphics/ppm/Vector3D.cpp

CMakeFiles/ppm.dir/Vector3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppm.dir/Vector3D.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/ppm/Vector3D.cpp > CMakeFiles/ppm.dir/Vector3D.cpp.i

CMakeFiles/ppm.dir/Vector3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppm.dir/Vector3D.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/ppm/Vector3D.cpp -o CMakeFiles/ppm.dir/Vector3D.cpp.s

CMakeFiles/ppm.dir/Vector3D.cpp.o.requires:

.PHONY : CMakeFiles/ppm.dir/Vector3D.cpp.o.requires

CMakeFiles/ppm.dir/Vector3D.cpp.o.provides: CMakeFiles/ppm.dir/Vector3D.cpp.o.requires
	$(MAKE) -f CMakeFiles/ppm.dir/build.make CMakeFiles/ppm.dir/Vector3D.cpp.o.provides.build
.PHONY : CMakeFiles/ppm.dir/Vector3D.cpp.o.provides

CMakeFiles/ppm.dir/Vector3D.cpp.o.provides.build: CMakeFiles/ppm.dir/Vector3D.cpp.o


CMakeFiles/ppm.dir/FrameBuffer.cpp.o: CMakeFiles/ppm.dir/flags.make
CMakeFiles/ppm.dir/FrameBuffer.cpp.o: ../FrameBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/ppm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ppm.dir/FrameBuffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ppm.dir/FrameBuffer.cpp.o -c /Users/Drax/Programming/Graphics/ppm/FrameBuffer.cpp

CMakeFiles/ppm.dir/FrameBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ppm.dir/FrameBuffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/ppm/FrameBuffer.cpp > CMakeFiles/ppm.dir/FrameBuffer.cpp.i

CMakeFiles/ppm.dir/FrameBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ppm.dir/FrameBuffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/ppm/FrameBuffer.cpp -o CMakeFiles/ppm.dir/FrameBuffer.cpp.s

CMakeFiles/ppm.dir/FrameBuffer.cpp.o.requires:

.PHONY : CMakeFiles/ppm.dir/FrameBuffer.cpp.o.requires

CMakeFiles/ppm.dir/FrameBuffer.cpp.o.provides: CMakeFiles/ppm.dir/FrameBuffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ppm.dir/build.make CMakeFiles/ppm.dir/FrameBuffer.cpp.o.provides.build
.PHONY : CMakeFiles/ppm.dir/FrameBuffer.cpp.o.provides

CMakeFiles/ppm.dir/FrameBuffer.cpp.o.provides.build: CMakeFiles/ppm.dir/FrameBuffer.cpp.o


# Object files for target ppm
ppm_OBJECTS = \
"CMakeFiles/ppm.dir/main.cpp.o" \
"CMakeFiles/ppm.dir/Vector2D.cpp.o" \
"CMakeFiles/ppm.dir/Vector3D.cpp.o" \
"CMakeFiles/ppm.dir/FrameBuffer.cpp.o"

# External object files for target ppm
ppm_EXTERNAL_OBJECTS =

ppm: CMakeFiles/ppm.dir/main.cpp.o
ppm: CMakeFiles/ppm.dir/Vector2D.cpp.o
ppm: CMakeFiles/ppm.dir/Vector3D.cpp.o
ppm: CMakeFiles/ppm.dir/FrameBuffer.cpp.o
ppm: CMakeFiles/ppm.dir/build.make
ppm: CMakeFiles/ppm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Drax/Programming/Graphics/ppm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ppm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ppm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ppm.dir/build: ppm

.PHONY : CMakeFiles/ppm.dir/build

CMakeFiles/ppm.dir/requires: CMakeFiles/ppm.dir/main.cpp.o.requires
CMakeFiles/ppm.dir/requires: CMakeFiles/ppm.dir/Vector2D.cpp.o.requires
CMakeFiles/ppm.dir/requires: CMakeFiles/ppm.dir/Vector3D.cpp.o.requires
CMakeFiles/ppm.dir/requires: CMakeFiles/ppm.dir/FrameBuffer.cpp.o.requires

.PHONY : CMakeFiles/ppm.dir/requires

CMakeFiles/ppm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ppm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ppm.dir/clean

CMakeFiles/ppm.dir/depend:
	cd /Users/Drax/Programming/Graphics/ppm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Drax/Programming/Graphics/ppm /Users/Drax/Programming/Graphics/ppm /Users/Drax/Programming/Graphics/ppm/build /Users/Drax/Programming/Graphics/ppm/build /Users/Drax/Programming/Graphics/ppm/build/CMakeFiles/ppm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ppm.dir/depend
