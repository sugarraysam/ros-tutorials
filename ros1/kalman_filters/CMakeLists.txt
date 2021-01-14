cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(kalman VERSION 1.0.0 DESCRIPTION "Kalman filters")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Sources
file(GLOB_RECURSE sources src/*.cc src/*.h)

# main
add_executable(kalman ${sources})
target_compile_options(kalman PUBLIC -std=c++17 -Wall)
