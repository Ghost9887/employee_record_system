cmake_minimum_required(VERSION 3.10)
project(employees)

file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cc
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(employees ${SOURCES})

target_compile_features(employees PRIVATE cxx_std_20)
