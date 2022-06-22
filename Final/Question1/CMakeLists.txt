cmake_minimum_required(VERSION 3.21)
project(Question1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Question1
        main.cpp
        Toy.cpp
        Toy.h)
