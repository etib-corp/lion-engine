# # cmake_minimum_required(VERSION 3.20)

# # project(lion-engine)

# # set(CMAKE_CXX_STANDARD 20)
# # set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # include(FetchContent)
# # include(cmake/Utils.cmake)

# # FetchContent_Declare(
# #     openal
# #     GIT_REPOSITORY https://github.com/kcat/openal-soft.git
# #     GIT_TAG 1.23.1
# # )

# # FetchContent_MakeAvailable(openal)

# # include_directories(include/ include/interface lib/SFML/dependencies)

# # set(LION_ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# # file(GLOB LIB_DIRS "lib/*")

# # foreach(dir ${LIB_DIRS})
# #     if (EXISTS "${dir}/CMakeLists.txt")
# #         message("${BoldGreen}Adding subdirectory: ${dir}")
# #         add_subdirectory(${dir})
# #     else ()
# #         message(WARNING "Skipping ${dir} - CMakeLists.txt file is missing")
# #     endif()
# # endforeach()


# # include_directories(${glm_SOURCE_DIR})

# # include_directories(${openal_SOURCE_DIR}/include)

# # file(GLOB_RECURSE SOURCES src/*.cpp)


# # add_library(lion-engine SHARED ${SOURCES})

# # target_link_libraries(lion-engine openal)




# # cmake_minimum_required(VERSION 3.20)

# # project(lion-engine)

# # set(CMAKE_CXX_STANDARD 20)
# # set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # include(FetchContent)
# # include(cmake/Utils.cmake)

# # FetchContent_Declare(
# #     openal
# #     GIT_REPOSITORY https://github.com/kcat/openal-soft.git
# #     GIT_TAG 1.23.1
# # )
# # FetchContent_MakeAvailable(openal)

# # FetchContent_Declare(
# #     lua
# #     GIT_REPOSITORY https://github.com/luaDist/lua.git
# #     GIT_TAG 5.2
# # )
# # FetchContent_MakeAvailable(lua)

# # include_directories(${lua_SOURCE_DIR}/src)
# # message(WARNING ${lua_SOURCE_DIR}/src)
# # include_directories(${openal_SOURCE_DIR}/include)

# # include_directories(include/ include/interface lib/SFML/dependencies)

# # set(LION_ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# # file(GLOB LIB_DIRS "lib/*")

# # foreach(dir ${LIB_DIRS})
# #     if (EXISTS "${dir}/CMakeLists.txt")
# #         message("${BoldGreen}Adding subdirectory: ${dir}")
# #         add_subdirectory(${dir})
# #     else ()
# #         message(WARNING "Skipping ${dir} - CMakeLists.txt file is missing")
# #     endif()
# # endforeach()


# # include_directories(${glm_SOURCE_DIR})

# # file(GLOB_RECURSE SOURCES src/*.cpp)


# # add_library(lion-engine SHARED ${SOURCES})

# # target_link_libraries(lion-engine openal liblua)

# cmake_minimum_required(VERSION 3.20)
# project(lion-engine)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(FetchContent)
# include(cmake/Utils.cmake)

# # Fetch OpenAL
# FetchContent_Declare(
#     openal
#     GIT_REPOSITORY https://github.com/kcat/openal-soft.git
#     GIT_TAG 1.23.1
# )
# FetchContent_MakeAvailable(openal)

# # Fetch Lua
# FetchContent_Declare(
#     lua
#     GIT_REPOSITORY https://github.com/lua/lua.git
#     GIT_TAG v5.4.4
# )
# FetchContent_MakeAvailable(lua)

# # Build Lua library
# file(GLOB LUA_SRC ${lua_SOURCE_DIR}/*.c)
# add_library(lua STATIC ${LUA_SRC})
# target_include_directories(lua PUBLIC ${lua_SOURCE_DIR})

# # Include directories
# include_directories(include/ include/interface lib/SFML/dependencies ${lua_SOURCE_DIR})

# # Set include directory variable
# set(LION_ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# # Add subdirectories in lib/
# file(GLOB LIB_DIRS "lib/*")
# foreach(dir ${LIB_DIRS})
#     if (EXISTS "${dir}/CMakeLists.txt")
#         message("${BoldGreen}Adding subdirectory: ${dir}")
#         add_subdirectory(${dir})
#     else()
#         message(WARNING "Skipping ${dir} - CMakeLists.txt file is missing")
#     endif()
# endforeach()

# # Include OpenAL headers
# include_directories(${openal_SOURCE_DIR}/include)

# # Source files
# file(GLOB_RECURSE SOURCES src/*.cpp)

# # Create lion-engine library
# add_library(lion-engine SHARED ${SOURCES})

# # Link libraries
# target_link_libraries(lion-engine openal lua)

# # Include Lua headers in lion-engine
# target_include_directories(lion-engine PUBLIC ${lua_SOURCE_DIR})


cmake_minimum_required(VERSION 3.20)
project(lion-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
include(cmake/Utils.cmake)

# Fetch OpenAL
FetchContent_Declare(
    openal
    GIT_REPOSITORY https://github.com/kcat/openal-soft.git
    GIT_TAG 1.23.1
)
FetchContent_MakeAvailable(openal)

# Fetch Lua
FetchContent_Declare(
    lua
    GIT_REPOSITORY https://github.com/lua/lua.git
    GIT_TAG v5.4.4
)
FetchContent_MakeAvailable(lua)

# Build Lua library
file(GLOB LUA_ALL_SRC ${lua_SOURCE_DIR}/*.c)

# Exclude lua.c, luac.c, onelua.c
set(LUA_EXCLUDE_SRC
    ${lua_SOURCE_DIR}/lua.c
    # ${lua_SOURCE_DIR}/luac.c
    ${lua_SOURCE_DIR}/onelua.c
)

# Remove excluded files from the list
foreach(file ${LUA_EXCLUDE_SRC})
    list(REMOVE_ITEM LUA_ALL_SRC ${file})
endforeach()

add_library(lua SHARED ${LUA_ALL_SRC})
target_include_directories(lua PUBLIC ${lua_SOURCE_DIR})
set_target_properties(lua PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Include directories
include_directories(
    include/
    include/interface
    lib/SFML/dependencies
    ${lua_SOURCE_DIR}
)

# Set include directory variable
set(LION_ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add subdirectories in lib/
file(GLOB LIB_DIRS "lib/*")
foreach(dir ${LIB_DIRS})
    if (EXISTS "${dir}/CMakeLists.txt")
        message("${BoldGreen}Adding subdirectory: ${dir}")
        add_subdirectory(${dir})
    else()
        message(WARNING "Skipping ${dir} - CMakeLists.txt file is missing")
    endif()
endforeach()

# Include OpenAL headers
include_directories(${openal_SOURCE_DIR}/include)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Create lion-engine library
add_library(lion-engine SHARED ${SOURCES})

# Link libraries
target_link_libraries(lion-engine PRIVATE openal lua)

# Include Lua headers in lion-engine
target_include_directories(lion-engine PUBLIC ${lua_SOURCE_DIR})
