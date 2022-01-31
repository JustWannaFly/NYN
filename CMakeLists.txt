# CMakeList.txt : CMake project for NYN, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("NYN")

add_subdirectory(include/SDL)

# Add source to this project's executable.
add_executable (NYN "src/NYN.cpp" "src/NYN.h")

target_link_libraries(${PROJECT_NAME}
	SDL2
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
