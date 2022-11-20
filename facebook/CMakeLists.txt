cmake_minimum_required(VERSION 3.10)

# set the project name
project(facebook)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    facebook/include
)

# add the executable
add_executable(
    quizz_app
    src/data_storing.cpp
    src/quizz_app.cpp
)
