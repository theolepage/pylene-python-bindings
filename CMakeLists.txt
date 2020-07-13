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

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE Pylene::Pylene)

# Main library
set(SRC
    include/pln/core/morpho.cpp
    include/pln/core/se.cpp
    src/python_bindings.cpp
)
pybind11_add_module(pylene SHARED ${SRC})
target_link_libraries(pylene PRIVATE Pylene::Pylene)