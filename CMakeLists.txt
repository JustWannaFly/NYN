# CMakeList.txt : CMake project for NYN, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("NYN")

add_subdirectory(include/SDL)

# Add source to this project's executable.
add_executable (NYN "NYN.cpp" "NYN.h")

# TODO: Add tests and install targets if needed.
