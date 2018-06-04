# CMake generated Testfile for 
# Source directory: C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM
# Build directory: C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM/build_test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(build_test "C:/Program Files/CMake/bin/cmake.exe" "--build" ".")
add_test(unit_test "./unit_test")
set_tests_properties(unit_test PROPERTIES  DEPENDS "build_test")
add_test(complexity_test "lizard" "-C" "10" "--warnings_only" ".")
set_tests_properties(complexity_test PROPERTIES  WORKING_DIRECTORY "C:/ti-software/R2D2/Build-environment/modules/MOVING_PLATFORM")
