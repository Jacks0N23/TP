cmake_minimum_required(VERSION 3.2)
project(TP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(TP ${SOURCE_FILES} Matrix.h search.h)