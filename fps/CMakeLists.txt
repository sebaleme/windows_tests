cmake_minimum_required(VERSION 3.10)

# set the project name
project(fps)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library( sdl SHARED IMPORTED)
set(SDL3_LIBRARIES "${CMAKE_SOURCE_DIR}/external/Release/SDL3.lib")

# add the executable
add_executable(
    fps 
    src/main.cpp
    src/init.cpp
    src/input.cpp
    src/ray_casting.cpp
)

target_include_directories(fps PUBLIC "${CMAKE_SOURCE_DIR}/external/include" "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(fps PUBLIC ${SDL3_LIBRARIES})

