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

# Include any dependencies generated for this target.
include app/CMakeFiles/utext.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/utext.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/utext.dir/flags.make

app/qrc_resources.cpp: ../app/resources/qmain.qss
app/qrc_resources.cpp: app/resources/resources.qrc.depends
app/qrc_resources.cpp: ../app/resources/resources.qrc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating qrc_resources.cpp"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Users/mlibovych/.brew/Cellar/qt/5.15.1/bin/rcc --name resources --output /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/qrc_resources.cpp /Users/mlibovych/Desktop/Qt/CPP-Utext/app/resources/resources.qrc

app/CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.o: app/CMakeFiles/utext.dir/flags.make
app/CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.o: app/utext_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app/CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.o"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.o -c /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/utext_autogen/mocs_compilation.cpp

app/CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.i"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/utext_autogen/mocs_compilation.cpp > CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.i

app/CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.s"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/utext_autogen/mocs_compilation.cpp -o CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.s

app/CMakeFiles/utext.dir/main.cpp.o: app/CMakeFiles/utext.dir/flags.make
app/CMakeFiles/utext.dir/main.cpp.o: ../app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object app/CMakeFiles/utext.dir/main.cpp.o"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utext.dir/main.cpp.o -c /Users/mlibovych/Desktop/Qt/CPP-Utext/app/main.cpp

app/CMakeFiles/utext.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utext.dir/main.cpp.i"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mlibovych/Desktop/Qt/CPP-Utext/app/main.cpp > CMakeFiles/utext.dir/main.cpp.i

app/CMakeFiles/utext.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utext.dir/main.cpp.s"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mlibovych/Desktop/Qt/CPP-Utext/app/main.cpp -o CMakeFiles/utext.dir/main.cpp.s

app/CMakeFiles/utext.dir/src/mainwindow.cpp.o: app/CMakeFiles/utext.dir/flags.make
app/CMakeFiles/utext.dir/src/mainwindow.cpp.o: ../app/src/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object app/CMakeFiles/utext.dir/src/mainwindow.cpp.o"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utext.dir/src/mainwindow.cpp.o -c /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/mainwindow.cpp

app/CMakeFiles/utext.dir/src/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utext.dir/src/mainwindow.cpp.i"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/mainwindow.cpp > CMakeFiles/utext.dir/src/mainwindow.cpp.i

app/CMakeFiles/utext.dir/src/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utext.dir/src/mainwindow.cpp.s"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/mainwindow.cpp -o CMakeFiles/utext.dir/src/mainwindow.cpp.s

app/CMakeFiles/utext.dir/src/textArea.cpp.o: app/CMakeFiles/utext.dir/flags.make
app/CMakeFiles/utext.dir/src/textArea.cpp.o: ../app/src/textArea.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object app/CMakeFiles/utext.dir/src/textArea.cpp.o"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utext.dir/src/textArea.cpp.o -c /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/textArea.cpp

app/CMakeFiles/utext.dir/src/textArea.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utext.dir/src/textArea.cpp.i"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/textArea.cpp > CMakeFiles/utext.dir/src/textArea.cpp.i

app/CMakeFiles/utext.dir/src/textArea.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utext.dir/src/textArea.cpp.s"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/textArea.cpp -o CMakeFiles/utext.dir/src/textArea.cpp.s

app/CMakeFiles/utext.dir/src/myTab.cpp.o: app/CMakeFiles/utext.dir/flags.make
app/CMakeFiles/utext.dir/src/myTab.cpp.o: ../app/src/myTab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object app/CMakeFiles/utext.dir/src/myTab.cpp.o"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utext.dir/src/myTab.cpp.o -c /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/myTab.cpp

app/CMakeFiles/utext.dir/src/myTab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utext.dir/src/myTab.cpp.i"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/myTab.cpp > CMakeFiles/utext.dir/src/myTab.cpp.i

app/CMakeFiles/utext.dir/src/myTab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utext.dir/src/myTab.cpp.s"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/myTab.cpp -o CMakeFiles/utext.dir/src/myTab.cpp.s

app/CMakeFiles/utext.dir/src/myTree.cpp.o: app/CMakeFiles/utext.dir/flags.make
app/CMakeFiles/utext.dir/src/myTree.cpp.o: ../app/src/myTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object app/CMakeFiles/utext.dir/src/myTree.cpp.o"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utext.dir/src/myTree.cpp.o -c /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/myTree.cpp

app/CMakeFiles/utext.dir/src/myTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utext.dir/src/myTree.cpp.i"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/myTree.cpp > CMakeFiles/utext.dir/src/myTree.cpp.i

app/CMakeFiles/utext.dir/src/myTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utext.dir/src/myTree.cpp.s"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mlibovych/Desktop/Qt/CPP-Utext/app/src/myTree.cpp -o CMakeFiles/utext.dir/src/myTree.cpp.s

app/CMakeFiles/utext.dir/qrc_resources.cpp.o: app/CMakeFiles/utext.dir/flags.make
app/CMakeFiles/utext.dir/qrc_resources.cpp.o: app/qrc_resources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object app/CMakeFiles/utext.dir/qrc_resources.cpp.o"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utext.dir/qrc_resources.cpp.o -c /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/qrc_resources.cpp

app/CMakeFiles/utext.dir/qrc_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utext.dir/qrc_resources.cpp.i"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/qrc_resources.cpp > CMakeFiles/utext.dir/qrc_resources.cpp.i

app/CMakeFiles/utext.dir/qrc_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utext.dir/qrc_resources.cpp.s"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/qrc_resources.cpp -o CMakeFiles/utext.dir/qrc_resources.cpp.s

# Object files for target utext
utext_OBJECTS = \
"CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/utext.dir/main.cpp.o" \
"CMakeFiles/utext.dir/src/mainwindow.cpp.o" \
"CMakeFiles/utext.dir/src/textArea.cpp.o" \
"CMakeFiles/utext.dir/src/myTab.cpp.o" \
"CMakeFiles/utext.dir/src/myTree.cpp.o" \
"CMakeFiles/utext.dir/qrc_resources.cpp.o"

# External object files for target utext
utext_EXTERNAL_OBJECTS =

../utext: app/CMakeFiles/utext.dir/utext_autogen/mocs_compilation.cpp.o
../utext: app/CMakeFiles/utext.dir/main.cpp.o
../utext: app/CMakeFiles/utext.dir/src/mainwindow.cpp.o
../utext: app/CMakeFiles/utext.dir/src/textArea.cpp.o
../utext: app/CMakeFiles/utext.dir/src/myTab.cpp.o
../utext: app/CMakeFiles/utext.dir/src/myTree.cpp.o
../utext: app/CMakeFiles/utext.dir/qrc_resources.cpp.o
../utext: app/CMakeFiles/utext.dir/build.make
../utext: /Users/mlibovych/.brew/Cellar/qt/5.15.1/lib/QtWidgets.framework/QtWidgets
../utext: /Users/mlibovych/.brew/Cellar/qt/5.15.1/lib/QtGui.framework/QtGui
../utext: /Users/mlibovych/.brew/Cellar/qt/5.15.1/lib/QtCore.framework/QtCore
../utext: app/CMakeFiles/utext.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mlibovych/Desktop/Qt/CPP-Utext/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ../../utext"
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utext.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/utext.dir/build: ../utext

.PHONY : app/CMakeFiles/utext.dir/build

app/CMakeFiles/utext.dir/clean:
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app && $(CMAKE_COMMAND) -P CMakeFiles/utext.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/utext.dir/clean

app/CMakeFiles/utext.dir/depend: app/qrc_resources.cpp
	cd /Users/mlibovych/Desktop/Qt/CPP-Utext/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mlibovych/Desktop/Qt/CPP-Utext /Users/mlibovych/Desktop/Qt/CPP-Utext/app /Users/mlibovych/Desktop/Qt/CPP-Utext/build /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app /Users/mlibovych/Desktop/Qt/CPP-Utext/build/app/CMakeFiles/utext.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/utext.dir/depend

