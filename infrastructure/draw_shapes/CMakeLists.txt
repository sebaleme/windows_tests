cmake_minimum_required(VERSION 3.10)

# set the project name
project(windows_tests)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
    draw_shapes 
    src/main.cpp
)