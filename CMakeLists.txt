cmake_minimum_required(VERSION 3.14)
project(triangles)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(google_tests)
add_executable(triangles MYStructs.h MyFunctions.h OctoTree.h main.cpp)
