cmake_minimum_required(VERSION 3.26)
project(c_sorts)

set(CMAKE_CXX_STANDARD 20)

add_executable(c_sorts main.cpp
        sorts.h
        sorts.cpp
        utils.cpp
        utils.h
        test.cpp
        test.h)
