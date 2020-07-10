cmake_minimum_required(VERSION 3.0)
project (CPPA
         DESCRIPTION "Sujet 1 : Polymorphisme statique/dynamique pour Python")

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Pylene REQUIRED)
find_package(GTest 1.8.1 REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

# BUILD OPTIONS
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3 -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}") # -Ofast -march=native")

# BUILD_TYPE (if not defined by the user)
if (NOT CMAKE_BUILD_TYPE)
    string(REGEX REPLACE ".*/build_" "" BUILD_NAME ${CMAKE_BINARY_DIR})
    # Default BUILD_TYPE is Release
    set(CMAKE_BUILD_TYPE Release)
    # If folder is named "build_debug" BUILD_TYPE is set to: Debug
    if(${BUILD_NAME} STREQUAL "Debug" OR ${BUILD_NAME} STREQUAL "debug")
        set(CMAKE_BUILD_TYPE Debug)
    endif()
    message(STATUS "Build type : ${CMAKE_BUILD_TYPE}")
endif()

# Sources
set(SRC
    src/example.cpp
    )
# add_library(pylene ${SRC})
# include_directories(src)

# TESTS
set(SRC_TESTS
    tests/unit_tests/example_test.cc
    #FIXME
    )

add_subdirectory(include/pybind11)
pybind11_add_module(pylene ${SRC})
target_link_libraries(pylene PRIVATE Pylene::Pylene)