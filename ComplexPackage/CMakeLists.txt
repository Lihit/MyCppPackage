cmake_minimum_required(VERSION 3.6)
project(ComplexPackage)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Complex.cpp Complex.h)
add_executable(ComplexPackage ${SOURCE_FILES})