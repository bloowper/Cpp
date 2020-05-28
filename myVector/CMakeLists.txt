cmake_minimum_required(VERSION 3.16)
project(myVector)

set(CMAKE_CXX_STANDARD 17)

add_executable(myVector main.cpp myVector.cpp myVector.h myVectorException.h)