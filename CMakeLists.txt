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
    infrastructure/exercices_diverse/inputs
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

# add the executable
add_executable(
    print_list 
    infrastructure/exercices_diverse/src/print_list.cpp
)

# add the executable
add_executable(
    leetcode 
    infrastructure/exercices_diverse/src/regex_search.cpp
)

# add the executable
add_executable(
    leetcode2 
    infrastructure/exercices_diverse/src/valid_parentheses.cpp
)

# add the executable
add_executable(
    leetcode_list 
    infrastructure/exercices_diverse/src/list_add_numbers.cpp
)

# add the executable
add_executable(
    hackerrank_list
    infrastructure/exercices_diverse/src/linked_list.cpp
)

# add the executable
add_executable(
    hackerrank_erase
    infrastructure/exercices_diverse/src/vector_erase.cpp
)
