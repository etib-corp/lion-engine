cmake_minimum_required(VERSION 3.20)

project(lion-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SOURCES src/*.cpp)

include_directories(include)

add_library(lion-engine SHARED ${SOURCES})


