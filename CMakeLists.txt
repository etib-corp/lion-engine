cmake_minimum_required(VERSION 3.25)

project(Lion VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(Lion SHARED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
target_sources(Lion PRIVATE ${SRC_FILES})

target_include_directories(Lion PRIVATE include)

include(FetchContent)

message(STATUS "Fetching SFML")

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)
FetchContent_MakeAvailable(SFML)

message(STATUS "SFML fetched")

target_link_libraries(Lion PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

# if(WIN32)
#     add_definitions(-DSFML_STATIC)
# elseif(UNIX)
#     set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# endif()
