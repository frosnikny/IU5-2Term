cmake_minimum_required(VERSION 3.20)
project(lab01)

set(CMAKE_CXX_STANDARD 14)

link_directories(../library_lab01/cmake-build-debug)

add_executable(lab01 main.cpp)

target_link_libraries(lab01 LINK_PUBLIC library_lab01)