cmake_minimum_required(VERSION 3.0)
project (CPPA
         DESCRIPTION "Polymorphisme statique/dynamique pour Python")

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Pylene REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
include_directories("src")

add_subdirectory(include/pybind11)

# Main library
set(SRC src/main.cpp)
add_library(core STATIC ${SRC})
set_target_properties(core PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(core PRIVATE Pylene::Pylene)

# Python extension
pybind11_add_module(pylene SHARED src/python_bindings.cpp)
target_link_libraries(pylene PRIVATE core)