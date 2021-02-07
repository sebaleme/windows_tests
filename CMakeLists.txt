cmake_minimum_required(VERSION 3.10)

# set the project name
project(windows_tests)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    infrastructure/state_machine/include
    infrastructure/smart_pointer
    infrastructure/exercices_diverse/include
)

# add the executable
add_executable(
    windows_tests 
    infrastructure/helloworld.cpp
    infrastructure/state_machine/src/state_machine.cpp
    infrastructure/state_machine/src/state_init.cpp
    infrastructure/state_machine/src/state_run.cpp
    infrastructure/exercices_diverse/src/containers.cpp
)

