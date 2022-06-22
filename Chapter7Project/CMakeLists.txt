cmake_minimum_required(VERSION 3.21)
project(Chapter7Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chapter7Project main.cpp ItemToPurchase.cpp ItemToPurchase.h ShoppingCart.cpp ShoppingCart.h)
