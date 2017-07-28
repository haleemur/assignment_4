cmake_minimum_required(VERSION 3.6)
project(shapes)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)

add_executable(shapes_run ${SOURCE_FILES})

include_directories(shapes)

add_subdirectory(shapes)

target_link_libraries(shapes_run shapes)
