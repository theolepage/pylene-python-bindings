# SETUP
cmake_minimum_required (VERSION 3.11)
project (CPPA
         DESCRIPTION "Sujet 1 : Polymorphisme statique/dynamique pour Python")

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

find_package(Pylene REQUIRED)
find_package(pybind11 REQUIRED)
find_package(GTest 1.8.1 REQUIRED)

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
add_library(SRC
    src/example.cpp
    )
include_directories(src)

# TESTS
set(SRC_TESTS
    tests/unit_tests/example_test.cc
    #FIXME
    )

# PYBIND (TEST FIXME)
pybind11_add_module(CPPA SOURCES)

# TESTS
find_package(GTest)
if (${GTEST_FOUND})
    enable_testing()
    # For each test file create an executable of test. Launched using ctest
    foreach(f IN LISTS SRC_TESTS)
        message(STATUS "TESTS : building file : ${f}")
        # Find the test_name by deleting the extension and the parent_dir
        string(REGEX REPLACE "\\.[^.]*$" "" F_WITHOUT_EXT ${f})
        string(REGEX REPLACE "[^/]*/" "" TEST_NAME ${F_WITHOUT_EXT})

        # Create an executable with all sources and lib needed
        add_executable(${TEST_NAME} EXCLUDE_FROM_ALL ${f})
        target_link_libraries(${TEST_NAME} PRIVATE
            SRC
            ${GTEST_BOTH_LIBRARIES}
        )

        # Add the executable created to the test list of ctest
        add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
        # Set timeout of the test to 3 seconds
        set_tests_properties(${TEST_NAME} PROPERTIES TIMEOUT 3)
    endforeach()
else()
    message(WARNING "Gtest not found... You will not be able to launch tests")
endif()
