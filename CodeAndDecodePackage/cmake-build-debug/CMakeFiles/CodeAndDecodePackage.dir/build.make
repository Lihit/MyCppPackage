# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/wenshao/JetBrain/Clion/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/wenshao/JetBrain/Clion/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CodeAndDecodePackage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CodeAndDecodePackage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CodeAndDecodePackage.dir/flags.make

CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o: CMakeFiles/CodeAndDecodePackage.dir/flags.make
CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o -c /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/main.cpp

CMakeFiles/CodeAndDecodePackage.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeAndDecodePackage.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/main.cpp > CMakeFiles/CodeAndDecodePackage.dir/main.cpp.i

CMakeFiles/CodeAndDecodePackage.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeAndDecodePackage.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/main.cpp -o CMakeFiles/CodeAndDecodePackage.dir/main.cpp.s

CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.requires

CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.provides: CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CodeAndDecodePackage.dir/build.make CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.provides

CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.provides.build: CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o


CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o: CMakeFiles/CodeAndDecodePackage.dir/flags.make
CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o: ../CodeAndDecode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o -c /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/CodeAndDecode.cpp

CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/CodeAndDecode.cpp > CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.i

CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/CodeAndDecode.cpp -o CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.s

CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.requires:

.PHONY : CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.requires

CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.provides: CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.requires
	$(MAKE) -f CMakeFiles/CodeAndDecodePackage.dir/build.make CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.provides.build
.PHONY : CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.provides

CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.provides.build: CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o


# Object files for target CodeAndDecodePackage
CodeAndDecodePackage_OBJECTS = \
"CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o" \
"CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o"

# External object files for target CodeAndDecodePackage
CodeAndDecodePackage_EXTERNAL_OBJECTS =

CodeAndDecodePackage: CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o
CodeAndDecodePackage: CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o
CodeAndDecodePackage: CMakeFiles/CodeAndDecodePackage.dir/build.make
CodeAndDecodePackage: CMakeFiles/CodeAndDecodePackage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CodeAndDecodePackage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CodeAndDecodePackage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CodeAndDecodePackage.dir/build: CodeAndDecodePackage

.PHONY : CMakeFiles/CodeAndDecodePackage.dir/build

CMakeFiles/CodeAndDecodePackage.dir/requires: CMakeFiles/CodeAndDecodePackage.dir/main.cpp.o.requires
CMakeFiles/CodeAndDecodePackage.dir/requires: CMakeFiles/CodeAndDecodePackage.dir/CodeAndDecode.cpp.o.requires

.PHONY : CMakeFiles/CodeAndDecodePackage.dir/requires

CMakeFiles/CodeAndDecodePackage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CodeAndDecodePackage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CodeAndDecodePackage.dir/clean

CMakeFiles/CodeAndDecodePackage.dir/depend:
	cd /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug /home/wenshao/MyProjects/MyCppPackage/CodeAndDecodePackage/cmake-build-debug/CMakeFiles/CodeAndDecodePackage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CodeAndDecodePackage.dir/depend

