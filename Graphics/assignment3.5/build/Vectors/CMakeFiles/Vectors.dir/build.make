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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Drax/Programming/Graphics/assignment3.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Drax/Programming/Graphics/assignment3.5/build

# Include any dependencies generated for this target.
include Vectors/CMakeFiles/Vectors.dir/depend.make

# Include the progress variables for this target.
include Vectors/CMakeFiles/Vectors.dir/progress.make

# Include the compile flags for this target's objects.
include Vectors/CMakeFiles/Vectors.dir/flags.make

Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o: Vectors/CMakeFiles/Vectors.dir/flags.make
Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o: ../Vectors/Vector2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/assignment3.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vectors.dir/Vector2D.cpp.o -c /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector2D.cpp

Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vectors.dir/Vector2D.cpp.i"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector2D.cpp > CMakeFiles/Vectors.dir/Vector2D.cpp.i

Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vectors.dir/Vector2D.cpp.s"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector2D.cpp -o CMakeFiles/Vectors.dir/Vector2D.cpp.s

Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.requires:

.PHONY : Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.requires

Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.provides: Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.requires
	$(MAKE) -f Vectors/CMakeFiles/Vectors.dir/build.make Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.provides.build
.PHONY : Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.provides

Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.provides.build: Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o


Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o: Vectors/CMakeFiles/Vectors.dir/flags.make
Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o: ../Vectors/Vector3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/assignment3.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vectors.dir/Vector3D.cpp.o -c /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector3D.cpp

Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vectors.dir/Vector3D.cpp.i"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector3D.cpp > CMakeFiles/Vectors.dir/Vector3D.cpp.i

Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vectors.dir/Vector3D.cpp.s"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector3D.cpp -o CMakeFiles/Vectors.dir/Vector3D.cpp.s

Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.requires:

.PHONY : Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.requires

Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.provides: Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.requires
	$(MAKE) -f Vectors/CMakeFiles/Vectors.dir/build.make Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.provides.build
.PHONY : Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.provides

Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.provides.build: Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o


Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o: Vectors/CMakeFiles/Vectors.dir/flags.make
Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o: ../Vectors/Vector4D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/assignment3.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vectors.dir/Vector4D.cpp.o -c /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector4D.cpp

Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vectors.dir/Vector4D.cpp.i"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector4D.cpp > CMakeFiles/Vectors.dir/Vector4D.cpp.i

Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vectors.dir/Vector4D.cpp.s"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/assignment3.5/Vectors/Vector4D.cpp -o CMakeFiles/Vectors.dir/Vector4D.cpp.s

Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.requires:

.PHONY : Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.requires

Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.provides: Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.requires
	$(MAKE) -f Vectors/CMakeFiles/Vectors.dir/build.make Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.provides.build
.PHONY : Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.provides

Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.provides.build: Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o


# Object files for target Vectors
Vectors_OBJECTS = \
"CMakeFiles/Vectors.dir/Vector2D.cpp.o" \
"CMakeFiles/Vectors.dir/Vector3D.cpp.o" \
"CMakeFiles/Vectors.dir/Vector4D.cpp.o"

# External object files for target Vectors
Vectors_EXTERNAL_OBJECTS =

Vectors/libVectors.a: Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o
Vectors/libVectors.a: Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o
Vectors/libVectors.a: Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o
Vectors/libVectors.a: Vectors/CMakeFiles/Vectors.dir/build.make
Vectors/libVectors.a: Vectors/CMakeFiles/Vectors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Drax/Programming/Graphics/assignment3.5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libVectors.a"
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && $(CMAKE_COMMAND) -P CMakeFiles/Vectors.dir/cmake_clean_target.cmake
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vectors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Vectors/CMakeFiles/Vectors.dir/build: Vectors/libVectors.a

.PHONY : Vectors/CMakeFiles/Vectors.dir/build

Vectors/CMakeFiles/Vectors.dir/requires: Vectors/CMakeFiles/Vectors.dir/Vector2D.cpp.o.requires
Vectors/CMakeFiles/Vectors.dir/requires: Vectors/CMakeFiles/Vectors.dir/Vector3D.cpp.o.requires
Vectors/CMakeFiles/Vectors.dir/requires: Vectors/CMakeFiles/Vectors.dir/Vector4D.cpp.o.requires

.PHONY : Vectors/CMakeFiles/Vectors.dir/requires

Vectors/CMakeFiles/Vectors.dir/clean:
	cd /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors && $(CMAKE_COMMAND) -P CMakeFiles/Vectors.dir/cmake_clean.cmake
.PHONY : Vectors/CMakeFiles/Vectors.dir/clean

Vectors/CMakeFiles/Vectors.dir/depend:
	cd /Users/Drax/Programming/Graphics/assignment3.5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Drax/Programming/Graphics/assignment3.5 /Users/Drax/Programming/Graphics/assignment3.5/Vectors /Users/Drax/Programming/Graphics/assignment3.5/build /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors /Users/Drax/Programming/Graphics/assignment3.5/build/Vectors/CMakeFiles/Vectors.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Vectors/CMakeFiles/Vectors.dir/depend
