# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/mlibovych/.brew/Cellar/cmake/3.18.3/bin/cmake

# The command to remove a file.
RM = /Users/mlibovych/.brew/Cellar/cmake/3.18.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mlibovych/Desktop/Qt/CPP-Utext

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mlibovych/Desktop/Qt/CPP-Utext/build

# Utility rule file for utext_autogen.

# Include the progress variables for this target.
include app/CMakeFiles/utext_autogen.dir/progress.make

app/CMakeFiles/utext_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target utext"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Users/mlibovych/.brew/Cellar/cmake/3.18.3/bin/cmake -E cmake_autogen /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/CMakeFiles/utext_autogen.dir/AutogenInfo.json ""

utext_autogen: app/CMakeFiles/utext_autogen
utext_autogen: app/CMakeFiles/utext_autogen.dir/build.make

.PHONY : utext_autogen

# Rule to build all files generated by this target.
app/CMakeFiles/utext_autogen.dir/build: utext_autogen

.PHONY : app/CMakeFiles/utext_autogen.dir/build

app/CMakeFiles/utext_autogen.dir/clean:
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && $(CMAKE_COMMAND) -P CMakeFiles/utext_autogen.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/utext_autogen.dir/clean

app/CMakeFiles/utext_autogen.dir/depend:
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mlibovych/Desktop/Qt/CPP-Utext /Users/mlibovych/Desktop/Qt/CPP-Utext/app /Users/mlibovych/Desktop/Qt/CPP-Utext/build /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/CMakeFiles/utext_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/utext_autogen.dir/depend

