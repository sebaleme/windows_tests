cmake_minimum_required(VERSION 3.10)

# set the project name
project(hanoi_tower)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    include/hanoi_tower/
)

# add the executable
add_executable(
    hanoi_tower_app
    src/cube.cpp
    src/game.cpp
    src/hanoi_tower_s1.cpp
    src/stack.cpp
)
