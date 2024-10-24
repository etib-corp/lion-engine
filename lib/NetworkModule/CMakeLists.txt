cmake_minimum_required(VERSION 3.20)

project(NetworkModule)

file(GLOB_RECURSE ASIO_NETWORK_MODULE_SOURCES src/*.cpp ../../src/*.cpp)

message(STATUS "ASIO_NETWORK_MODULE_SOURCES: ${ASIO_NETWORK_MODULE_SOURCES}")

if (WIN32)
    add_compile_options(-DLIBRARY_EXPORTS)
endif(WIN32)

add_subdirectory(dependencies/boost-1.86.0)

include_directories(../../include)
include_directories(include)

add_library(NetworkModule SHARED ${ASIO_NETWORK_MODULE_SOURCES})

target_link_libraries(NetworkModule PRIVATE Boost::asio Boost::system Boost::iostreams)
set_target_properties(NetworkModule PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
