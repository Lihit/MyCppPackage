cmake_minimum_required(VERSION 3.6)
project(RandomPackage)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Random.cpp Random.h Matrix.cpp Matrix.h Complex.cpp Complex.h)
add_executable(RandomPackage ${SOURCE_FILES})