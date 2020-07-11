cmake_minimum_required(VERSION 3.0)
project (CPPA
         DESCRIPTION "Sujet 1 : Polymorphisme statique/dynamique pour Python")

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
find_package(Pylene REQUIRED)

# BUILD OPTIONS
set(CMAKE_CXX_STANDARD 20)
include_directories("src")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3 -fsanitize=address")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}") # -Ofast -march=native")

add_subdirectory(include/pybind11)

# Main library
set(SRC src/main.cpp)
add_library(core STATIC ${SRC})
set_target_properties(core PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(core PRIVATE Pylene::Pylene)

# Python extension
pybind11_add_module(pylene src/python_bindings.cpp)
target_link_libraries(pylene PRIVATE core)