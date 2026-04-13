cmake_minimum_required(VERSION 3.10)
project(employees)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cc
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(employees ${SOURCES})


