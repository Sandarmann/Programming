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
CMAKE_SOURCE_DIR = /Users/Drax/Programming/Graphics/assignment4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Drax/Programming/Graphics/assignment4/build

# Include any dependencies generated for this target.
include Objects/CMakeFiles/Objects.dir/depend.make

# Include the progress variables for this target.
include Objects/CMakeFiles/Objects.dir/progress.make

# Include the compile flags for this target's objects.
include Objects/CMakeFiles/Objects.dir/flags.make

Objects/CMakeFiles/Objects.dir/Sphere.cpp.o: Objects/CMakeFiles/Objects.dir/flags.make
Objects/CMakeFiles/Objects.dir/Sphere.cpp.o: ../Objects/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/assignment4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Objects/CMakeFiles/Objects.dir/Sphere.cpp.o"
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Objects.dir/Sphere.cpp.o -c /Users/Drax/Programming/Graphics/assignment4/Objects/Sphere.cpp

Objects/CMakeFiles/Objects.dir/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Objects.dir/Sphere.cpp.i"
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/assignment4/Objects/Sphere.cpp > CMakeFiles/Objects.dir/Sphere.cpp.i

Objects/CMakeFiles/Objects.dir/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Objects.dir/Sphere.cpp.s"
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/assignment4/Objects/Sphere.cpp -o CMakeFiles/Objects.dir/Sphere.cpp.s

Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.requires:

.PHONY : Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.requires

Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.provides: Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.requires
	$(MAKE) -f Objects/CMakeFiles/Objects.dir/build.make Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.provides.build
.PHONY : Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.provides

Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.provides.build: Objects/CMakeFiles/Objects.dir/Sphere.cpp.o


Objects/CMakeFiles/Objects.dir/Triangle.cpp.o: Objects/CMakeFiles/Objects.dir/flags.make
Objects/CMakeFiles/Objects.dir/Triangle.cpp.o: ../Objects/Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Drax/Programming/Graphics/assignment4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Objects/CMakeFiles/Objects.dir/Triangle.cpp.o"
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Objects.dir/Triangle.cpp.o -c /Users/Drax/Programming/Graphics/assignment4/Objects/Triangle.cpp

Objects/CMakeFiles/Objects.dir/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Objects.dir/Triangle.cpp.i"
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Drax/Programming/Graphics/assignment4/Objects/Triangle.cpp > CMakeFiles/Objects.dir/Triangle.cpp.i

Objects/CMakeFiles/Objects.dir/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Objects.dir/Triangle.cpp.s"
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Drax/Programming/Graphics/assignment4/Objects/Triangle.cpp -o CMakeFiles/Objects.dir/Triangle.cpp.s

Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.requires:

.PHONY : Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.requires

Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.provides: Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.requires
	$(MAKE) -f Objects/CMakeFiles/Objects.dir/build.make Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.provides.build
.PHONY : Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.provides

Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.provides.build: Objects/CMakeFiles/Objects.dir/Triangle.cpp.o


# Object files for target Objects
Objects_OBJECTS = \
"CMakeFiles/Objects.dir/Sphere.cpp.o" \
"CMakeFiles/Objects.dir/Triangle.cpp.o"

# External object files for target Objects
Objects_EXTERNAL_OBJECTS =

Objects/libObjects.a: Objects/CMakeFiles/Objects.dir/Sphere.cpp.o
Objects/libObjects.a: Objects/CMakeFiles/Objects.dir/Triangle.cpp.o
Objects/libObjects.a: Objects/CMakeFiles/Objects.dir/build.make
Objects/libObjects.a: Objects/CMakeFiles/Objects.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Drax/Programming/Graphics/assignment4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libObjects.a"
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && $(CMAKE_COMMAND) -P CMakeFiles/Objects.dir/cmake_clean_target.cmake
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Objects.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Objects/CMakeFiles/Objects.dir/build: Objects/libObjects.a

.PHONY : Objects/CMakeFiles/Objects.dir/build

Objects/CMakeFiles/Objects.dir/requires: Objects/CMakeFiles/Objects.dir/Sphere.cpp.o.requires
Objects/CMakeFiles/Objects.dir/requires: Objects/CMakeFiles/Objects.dir/Triangle.cpp.o.requires

.PHONY : Objects/CMakeFiles/Objects.dir/requires

Objects/CMakeFiles/Objects.dir/clean:
	cd /Users/Drax/Programming/Graphics/assignment4/build/Objects && $(CMAKE_COMMAND) -P CMakeFiles/Objects.dir/cmake_clean.cmake
.PHONY : Objects/CMakeFiles/Objects.dir/clean

Objects/CMakeFiles/Objects.dir/depend:
	cd /Users/Drax/Programming/Graphics/assignment4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Drax/Programming/Graphics/assignment4 /Users/Drax/Programming/Graphics/assignment4/Objects /Users/Drax/Programming/Graphics/assignment4/build /Users/Drax/Programming/Graphics/assignment4/build/Objects /Users/Drax/Programming/Graphics/assignment4/build/Objects/CMakeFiles/Objects.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Objects/CMakeFiles/Objects.dir/depend

