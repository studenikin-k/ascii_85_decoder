cmake_minimum_required(VERSION 3.28)
project(ascii_85_decoder)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp
        coder.cpp
        coder.h
        decoder.h
        decoder.cpp)
