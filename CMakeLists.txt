cmake_minimum_required(VERSION 3.16)

project(race_simulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Transport)
add_subdirectory(Game)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE game)
