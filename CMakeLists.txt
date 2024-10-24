cmake_minimum_required(VERSION 3.20)

project(lion-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB LIB_DIRS "lib/*")
foreach(dir ${LIB_DIRS})
    add_subdirectory(${dir})
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

include_directories(include/)

add_library(lion-engine SHARED ${SOURCES})
target_link_libraries(lion-engine PRIVATE glm::glm)

file(GLOB_RECURSE MAIN main.cpp)

add_executable(main ${MAIN})

target_link_libraries(main lion-engine-SFML)
