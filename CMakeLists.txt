cmake_minimum_required(VERSION 3.22)
project(triangles)

set(CMAKE_CXX_STANDARD 20)

add_executable(triangles MYStructs.h MyFunctions.h OctoTree.h main.cpp)
