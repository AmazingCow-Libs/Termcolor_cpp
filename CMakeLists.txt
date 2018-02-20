##~---------------------------------------------------------------------------##
##                     _______  _______  _______  _     _                     ##
##                    |   _   ||       ||       || | _ | |                    ##
##                    |  |_|  ||       ||   _   || || || |                    ##
##                    |       ||       ||  | |  ||       |                    ##
##                    |       ||      _||  |_|  ||       |                    ##
##                    |   _   ||     |_ |       ||   _   |                    ##
##                    |__| |__||_______||_______||__| |__|                    ##
##                             www.amazingcow.com                             ##
##  File      : CMakeLists.txt                                                ##
##  Project   : libtermcolor                                                  ##
##  Date      : Feb 19, 2018                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : n2omatt <n2omatt@amazingcow.com>                              ##
##  Copyright : AmazingCow - 2018                                             ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##


cmake_minimum_required(VERSION 3.5)

##------------------------------------------------------------------------------
## Project Settings.
project(libtermcolor)


##------------------------------------------------------------------------------
## Sources.
add_library(libtermcolor
    termcolor/src/Config.cpp
    termcolor/src/Functions.cpp
)

##------------------------------------------------------------------------------
## Include directories.
target_include_directories(libtermcolor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


##------------------------------------------------------------------------------
## Dependencies.
target_link_libraries(libtermcolor LINK_PUBLIC acow_nt_posix)
