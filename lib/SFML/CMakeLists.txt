cmake_minimum_required(VERSION 3.20)

project(lion-engine-SFML)

file(GLOB_RECURSE LION_SFML_SOURCES src/*.cpp ../../src/*.cpp)


if (WIN32)
    add_compile_options(-DLIBRARY_EXPORTS)
endif(WIN32)

add_subdirectory(dependencies/SFML-2.6.1)

include_directories(../../include/interface)
include_directories(include)

add_library(lion-engine-SFML SHARED ${LION_SFML_SOURCES})

target_link_libraries(lion-engine-SFML PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
# set_target_properties(NetworkModule PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
