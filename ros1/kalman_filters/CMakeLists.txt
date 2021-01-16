cmake_minimum_required(VERSION 3.5.0)
project(kalman VERSION 1.0.0 DESCRIPTION "Kalman filters")

# Compilation database => compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# main && sources
file(GLOB_RECURSE sources src/*.cc src/*.h)
add_executable(${PROJECT_NAME} ${sources})
target_compile_options(${PROJECT_NAME} PUBLIC -std=c++17 -Wall)

# External libraries
# libeigen/eigen
find_package(Git QUIET)
if(GIT_FOUND)
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Git submodules update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}")
        endif()
    endif()
endif()
add_subdirectory(external/eigen)

# includes
target_include_directories(${PROJECT_NAME} PUBLIC external/eigen)

# linking
# target_link_directories(${PROJECT_NAME})
# target_link_libraries(${PROJECT_NAME})
