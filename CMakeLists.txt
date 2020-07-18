cmake_minimum_required(VERSION 3.0)
project (CPPA
         DESCRIPTION "Polymorphisme statique/dynamique pour Python")

# Dependencies
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Pylene REQUIRED)
find_package(pybind11 REQUIRED)

# Build options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
include_directories("src")

# Main library
set(SRC
    src/python_bindings.cpp
)
pybind11_add_module(pylene SHARED ${SRC})
target_link_libraries(pylene PRIVATE Pylene::Pylene)

# Tests
add_custom_target(test)
add_dependencies(test pylene)
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
    add_custom_command(TARGET test
        COMMAND cp "${CMAKE_BINARY_DIR}/pylene*.so" "${CMAKE_SOURCE_DIR}/tests/"
        COMMAND Python3::Interpreter -m unittest discover -v -s ${CMAKE_SOURCE_DIR}/tests
        COMMAND rm "${CMAKE_SOURCE_DIR}/tests/pylene*.so"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
        )
else()
    add_custom_command(TARGET test
        COMMAND echo "Python3 was not found, you will not be able to launch tests")
    MESSAGE(WARNING "Python3 was not found, you will not be able to launch tests")
endif()