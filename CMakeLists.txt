cmake_minimum_required(VERSION 3.28)
project(ascii85_decoder)

set(CMAKE_CXX_STANDARD 20)


add_executable(ascii85
        main.cpp
        coder.cpp
        coder.h
        decoder.cpp
        decoder.h)

install(TARGETS ascii85 RUNTIME DESTINATION bin)



find_package(GTest REQUIRED)

add_executable(test
        test.cpp
        coder.cpp
        decoder.cpp)


target_link_libraries(test GTest::GTest GTest::Main)
