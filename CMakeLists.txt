cmake_minimum_required(VERSION 3.7)
project(hw4_new)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES EscapeRoomWrapper.cpp EscapeRoom.c Enigma.cpp
        tests/Company_Ostream_test.cpp
        Company.cpp Company.h kidsRoom.cpp ScaryRoom.cpp)
add_executable(hw4_new ${SOURCE_FILES})