cmake_minimum_required(VERSION 3.10)

# set the project name
project(fps)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Import SDL library
add_library( sdl SHARED IMPORTED)
set(SDL3_LIBRARIES "${CMAKE_SOURCE_DIR}/external/Release/SDL3.lib")

# Import GTests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# add the executable
add_executable(
    fps 
    src/main.cpp
    src/colors.cpp
    src/init.cpp
    src/input.cpp
    src/map.cpp
    src/map_rendering_bev.cpp
    src/map_rendering_fv.cpp
    src/player_rendering_bev.cpp
    src/state_player.cpp
)

target_include_directories(fps PUBLIC "${CMAKE_SOURCE_DIR}/external/include" "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(fps PUBLIC ${SDL3_LIBRARIES})


enable_testing()

add_executable(
  fps_ut
  test/map_ut.cpp
  src/map.cpp
  test/map_rendering_fv_ut.cpp
  src/map_rendering_fv.cpp
  src/colors.cpp
)

target_include_directories(fps_ut PUBLIC "${CMAKE_SOURCE_DIR}/external/include" "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(
  fps_ut
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(fps_ut)


