include_directories(../../include/interface)
include_directories(include)

file(GLOB_RECURSE CLIENT_CORE_MODULE_SOURCES src/*.cpp)
file(GLOB_RECURSE SOURCES ../../src/*.cpp)

add_library(ClientCoreModule SHARED ${CLIENT_CORE_MODULE_SOURCES} ${SOURCES})
