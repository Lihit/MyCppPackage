cmake_minimum_required(VERSION 3.6)
project(CodeAndDecodePackage)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CodeAndDecode.cpp CodeAndDecode.h)
add_executable(CodeAndDecodePackage ${SOURCE_FILES})