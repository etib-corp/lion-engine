cmake_minimum_required(VERSION 3.20)

project(lion-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(cmake/Utils.cmake)

include_directories(include/ include/interface)

set(LION_ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB LIB_DIRS "lib/*")

foreach(dir ${LIB_DIRS})
    if (EXISTS "${dir}/CMakeLists.txt")
        message("${BoldGreen}Adding subdirectory: ${dir}")
        add_subdirectory(${dir})
    else ()
        message(WARNING "Skipping ${dir} - CMakeLists.txt file is missing")
    endif()
endforeach()

include(FetchContent)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
)

FetchContent_MakeAvailable(glm)

include_directories(${glm_SOURCE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)


add_library(lion-engine SHARED ${SOURCES})

