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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/agnar/git/SENAC/CVtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/agnar/git/SENAC/CVtest/buil

# Include any dependencies generated for this target.
include CMakeFiles/CVtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CVtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CVtest.dir/flags.make

CMakeFiles/CVtest.dir/DisplayImage.cpp.o: CMakeFiles/CVtest.dir/flags.make
CMakeFiles/CVtest.dir/DisplayImage.cpp.o: ../DisplayImage.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/agnar/git/SENAC/CVtest/buil/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/CVtest.dir/DisplayImage.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CVtest.dir/DisplayImage.cpp.o -c /home/agnar/git/SENAC/CVtest/DisplayImage.cpp

CMakeFiles/CVtest.dir/DisplayImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CVtest.dir/DisplayImage.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/agnar/git/SENAC/CVtest/DisplayImage.cpp > CMakeFiles/CVtest.dir/DisplayImage.cpp.i

CMakeFiles/CVtest.dir/DisplayImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CVtest.dir/DisplayImage.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/agnar/git/SENAC/CVtest/DisplayImage.cpp -o CMakeFiles/CVtest.dir/DisplayImage.cpp.s

CMakeFiles/CVtest.dir/DisplayImage.cpp.o.requires:
.PHONY : CMakeFiles/CVtest.dir/DisplayImage.cpp.o.requires

CMakeFiles/CVtest.dir/DisplayImage.cpp.o.provides: CMakeFiles/CVtest.dir/DisplayImage.cpp.o.requires
	$(MAKE) -f CMakeFiles/CVtest.dir/build.make CMakeFiles/CVtest.dir/DisplayImage.cpp.o.provides.build
.PHONY : CMakeFiles/CVtest.dir/DisplayImage.cpp.o.provides

CMakeFiles/CVtest.dir/DisplayImage.cpp.o.provides.build: CMakeFiles/CVtest.dir/DisplayImage.cpp.o

# Object files for target CVtest
CVtest_OBJECTS = \
"CMakeFiles/CVtest.dir/DisplayImage.cpp.o"

# External object files for target CVtest
CVtest_EXTERNAL_OBJECTS =

CVtest: CMakeFiles/CVtest.dir/DisplayImage.cpp.o
CVtest: CMakeFiles/CVtest.dir/build.make
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
CVtest: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
CVtest: CMakeFiles/CVtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable CVtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CVtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CVtest.dir/build: CVtest
.PHONY : CMakeFiles/CVtest.dir/build

CMakeFiles/CVtest.dir/requires: CMakeFiles/CVtest.dir/DisplayImage.cpp.o.requires
.PHONY : CMakeFiles/CVtest.dir/requires

CMakeFiles/CVtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CVtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CVtest.dir/clean

CMakeFiles/CVtest.dir/depend:
	cd /home/agnar/git/SENAC/CVtest/buil && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/agnar/git/SENAC/CVtest /home/agnar/git/SENAC/CVtest /home/agnar/git/SENAC/CVtest/buil /home/agnar/git/SENAC/CVtest/buil /home/agnar/git/SENAC/CVtest/buil/CMakeFiles/CVtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CVtest.dir/depend

