# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts"

# Include any dependencies generated for this target.
include common/CMakeFiles/common_rgba.dir/depend.make

# Include the progress variables for this target.
include common/CMakeFiles/common_rgba.dir/progress.make

# Include the compile flags for this target's objects.
include common/CMakeFiles/common_rgba.dir/flags.make

common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o: common/CMakeFiles/common_rgba.dir/flags.make
common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o: common/map_rgba.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o"
	cd "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" && /opt/local/bin/gcc   $(CXX_DEFINES) $(CXX_FLAGS)  -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -o CMakeFiles/common_rgba.dir/map_rgba.cpp.o -c "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common/map_rgba.cpp"

common/CMakeFiles/common_rgba.dir/map_rgba.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common_rgba.dir/map_rgba.cpp.i"
	cd "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" && /opt/local/bin/gcc  $(CXX_DEFINES) $(CXX_FLAGS)  -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -E "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common/map_rgba.cpp" > CMakeFiles/common_rgba.dir/map_rgba.cpp.i

common/CMakeFiles/common_rgba.dir/map_rgba.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common_rgba.dir/map_rgba.cpp.s"
	cd "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" && /opt/local/bin/gcc  $(CXX_DEFINES) $(CXX_FLAGS)  -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16 -S "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common/map_rgba.cpp" -o CMakeFiles/common_rgba.dir/map_rgba.cpp.s

common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.requires:
.PHONY : common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.requires

common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.provides: common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common_rgba.dir/build.make common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.provides.build
.PHONY : common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.provides

common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.provides.build: common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o

# Object files for target common_rgba
common_rgba_OBJECTS = \
"CMakeFiles/common_rgba.dir/map_rgba.cpp.o"

# External object files for target common_rgba
common_rgba_EXTERNAL_OBJECTS =

common/libcommon_rgba.a: common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o
common/libcommon_rgba.a: common/CMakeFiles/common_rgba.dir/build.make
common/libcommon_rgba.a: common/CMakeFiles/common_rgba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libcommon_rgba.a"
	cd "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" && $(CMAKE_COMMAND) -P CMakeFiles/common_rgba.dir/cmake_clean_target.cmake
	cd "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common_rgba.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/CMakeFiles/common_rgba.dir/build: common/libcommon_rgba.a
.PHONY : common/CMakeFiles/common_rgba.dir/build

common/CMakeFiles/common_rgba.dir/requires: common/CMakeFiles/common_rgba.dir/map_rgba.cpp.o.requires
.PHONY : common/CMakeFiles/common_rgba.dir/requires

common/CMakeFiles/common_rgba.dir/clean:
	cd "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" && $(CMAKE_COMMAND) -P CMakeFiles/common_rgba.dir/cmake_clean.cmake
.PHONY : common/CMakeFiles/common_rgba.dir/clean

common/CMakeFiles/common_rgba.dir/depend:
	cd "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts" "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts" "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common" "/Volumes/1Tb Macintosh HD/Users/Jed/Desktop/PROGRAMMING/uts/common/CMakeFiles/common_rgba.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : common/CMakeFiles/common_rgba.dir/depend
