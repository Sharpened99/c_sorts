cmake_minimum_required(VERSION 3.26)
project(c_sorts)

set(CMAKE_CXX_STANDARD 17)

message("Build Type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    add_compile_definitions(DEBUG_BUILD)
endif ()

add_subdirectory(src)