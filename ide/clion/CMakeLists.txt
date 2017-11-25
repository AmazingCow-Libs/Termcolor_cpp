cmake_minimum_required(VERSION 3.8)
project(clion)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 11)

add_definitions(-DAMAZINGCOW_LIBTERMCOLOR_SHOWCASE_TEST_ENABLED)

set(SOURCE_FILES
    ../../termcolor/termcolor.h
    ../../termcolor/include/Color.h
    ../../termcolor/include/Config.h
    ../../termcolor/include/Constants.h
    ../../termcolor/include/Functions.h
    ../../termcolor/include/termcolor_Utils.h
        ../../termcolor/src/Functions.cpp

    ../../test/main.cpp
        ../../termcolor/src/Config.cpp)

add_executable(clion ${SOURCE_FILES})
