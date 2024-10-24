cmake_minimum_required(VERSION 3.20)

project(lion-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SOURCES_INTERFACE src/interface/*.cpp)

file(GLOB_RECURSE SOURCES_SFML src/SFML/*.cpp)

include_directories(include/interface include/SFML)

add_library(lion-engine-SFML SHARED ${SOURCES_SFML} ${SOURCES_INTERFACE})

target_link_libraries(lion-engine-SFML sfml-graphics sfml-window sfml-system)

file(GLOB_RECURSE MAIN main.cpp)

add_executable(main ${MAIN})

target_link_libraries(main lion-engine-SFML)
