cmake_minimum_required(VERSION 3.21)
project(Chapter8Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chapter8Project main.cpp Song.cpp Song.h Playlist.cpp Playlist.h)
