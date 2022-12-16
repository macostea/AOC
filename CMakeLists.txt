# CMakeList.txt : CMake project for AdventOfCode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("AdventOfCode")

# Add source to this project's executable.
add_executable (AdventOfCode "AdventOfCode.cpp" "AdventOfCode.h"  "src/DayOne.cpp"  "include/Day.h" "src/DayTwo.cpp" "src/DayThree.cpp"   "src/DayFour.cpp")
target_include_directories (AdventOfCode PRIVATE "include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AdventOfCode PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
