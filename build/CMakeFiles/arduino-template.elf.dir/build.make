# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build

# Include any dependencies generated for this target.
include CMakeFiles/arduino-template.elf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arduino-template.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arduino-template.elf.dir/flags.make

CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.obj: CMakeFiles/arduino-template.elf.dir/flags.make
CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.obj: C:/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.obj"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.obj   -c C:/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c

CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.i"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c > CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.i

CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.s"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c -o CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.s

CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.obj: CMakeFiles/arduino-template.elf.dir/flags.make
CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.obj: ../src/wrap-hwlib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.obj"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.obj -c C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/wrap-hwlib.cpp

CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.i"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/wrap-hwlib.cpp > CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.i

CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.s"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/wrap-hwlib.cpp -o CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.s

CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.obj: CMakeFiles/arduino-template.elf.dir/flags.make
CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.obj: ../src/libc-stub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.obj"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.obj -c C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/libc-stub.cpp

CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.i"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/libc-stub.cpp > CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.i

CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.s"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/libc-stub.cpp -o CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.s

CMakeFiles/arduino-template.elf.dir/src/main.cpp.obj: CMakeFiles/arduino-template.elf.dir/flags.make
CMakeFiles/arduino-template.elf.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/arduino-template.elf.dir/src/main.cpp.obj"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arduino-template.elf.dir/src/main.cpp.obj -c C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/main.cpp

CMakeFiles/arduino-template.elf.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduino-template.elf.dir/src/main.cpp.i"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/main.cpp > CMakeFiles/arduino-template.elf.dir/src/main.cpp.i

CMakeFiles/arduino-template.elf.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduino-template.elf.dir/src/main.cpp.s"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/main.cpp -o CMakeFiles/arduino-template.elf.dir/src/main.cpp.s

CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.obj: CMakeFiles/arduino-template.elf.dir/flags.make
CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.obj: ../src/moving-platform.CPP
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.obj"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.obj -c C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/moving-platform.CPP

CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.i"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/moving-platform.CPP > CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.i

CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.s"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/src/moving-platform.CPP -o CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.s

# Object files for target arduino-template.elf
arduino__template_elf_OBJECTS = \
"CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.obj" \
"CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.obj" \
"CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.obj" \
"CMakeFiles/arduino-template.elf.dir/src/main.cpp.obj" \
"CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.obj"

# External object files for target arduino-template.elf
arduino__template_elf_EXTERNAL_OBJECTS =

arduino-template.elf: CMakeFiles/arduino-template.elf.dir/C_/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps/startup_sam3xa.c.obj
arduino-template.elf: CMakeFiles/arduino-template.elf.dir/src/wrap-hwlib.cpp.obj
arduino-template.elf: CMakeFiles/arduino-template.elf.dir/src/libc-stub.cpp.obj
arduino-template.elf: CMakeFiles/arduino-template.elf.dir/src/main.cpp.obj
arduino-template.elf: CMakeFiles/arduino-template.elf.dir/src/moving-platform.CPP.obj
arduino-template.elf: CMakeFiles/arduino-template.elf.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable arduino-template.elf"
	"C:/Program Files (x86)/GNU Tools ARM Embedded/7 2017-q4-major/bin/arm-none-eabi-g++.exe"   -std=c++14 -O3 -Wall -Wextra -pedantic-errors -Wfatal-errors -Wcast-align -Wmissing-declarations -Wredundant-decls -Wuninitialized -Wno-unused-parameter -Wno-missing-field-initializers -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -mcpu=cortex-m3 -mthumb -fomit-frame-pointer -march=armv7-m -fno-exceptions    -nostartfiles -nostdlib -Wl,--defsym=STACK_SIZE=92160 -Tsam3x8e_flash.ld -Wl,--gc-sections $(arduino__template_elf_OBJECTS) $(arduino__template_elf_EXTERNAL_OBJECTS)  -o arduino-template.elf  -LC:/ti-software/R2D2/Build-environment/toolchain/targets/arm32/cm3/atmel/sam3x/sam3x8e/deps -lgcc 

# Rule to build all files generated by this target.
CMakeFiles/arduino-template.elf.dir/build: arduino-template.elf

.PHONY : CMakeFiles/arduino-template.elf.dir/build

CMakeFiles/arduino-template.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arduino-template.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arduino-template.elf.dir/clean

CMakeFiles/arduino-template.elf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build/CMakeFiles/arduino-template.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arduino-template.elf.dir/depend

