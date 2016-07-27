cmake_minimum_required(VERSION 3.3)
project(jianzhiOffer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  level1/buySnacks/main.cpp)
add_executable(hihoCode ${SOURCE_FILES})