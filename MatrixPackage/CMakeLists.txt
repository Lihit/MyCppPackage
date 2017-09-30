cmake_minimum_required(VERSION 3.6)
project(MatrixPackage)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Matrix.cpp Matrix.h)
add_executable(MatrixPackage ${SOURCE_FILES})