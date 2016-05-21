cmake_minimum_required(VERSION 3.5)
project(OCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp StopWatch.h)
add_executable(OCpp ${SOURCE_FILES})
