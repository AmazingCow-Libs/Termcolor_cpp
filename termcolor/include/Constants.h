//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Constants.h                                                   //
//  Project   : libtermcolor                                                  //
//  Date      : Nov 24, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// libtermcolor
#include "termcolor_Utils.h"


NS_TERMCOLOR_BEGIN

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
constexpr int NONE  = 0;
constexpr int RESET = 0;

//------------------------------------------------------------------------------
// Foreground Colors.
constexpr int GREY    = 30;
constexpr int RED     = 31;
constexpr int GREEN   = 32;
constexpr int YELLOW  = 33;
constexpr int BLUE    = 34;
constexpr int MAGENTA = 35;
constexpr int CYAN    = 36;
constexpr int WHITE   = 37;

//------------------------------------------------------------------------------
// Background Colors.
constexpr int ON_GREY    = 40;
constexpr int ON_RED     = 41;
constexpr int ON_GREEN   = 42;
constexpr int ON_YELLOW  = 43;
constexpr int ON_BLUE    = 44;
constexpr int ON_MAGENTA = 45;
constexpr int ON_CYAN    = 46;
constexpr int ON_WHITE   = 47;

//------------------------------------------------------------------------------
// Attributes.
constexpr int BLINK     = 5;
constexpr int BOLD      = 1;
constexpr int CONCEALED = 8;
constexpr int DARK      = 2;
constexpr int REVERSE   = 7;
constexpr int UNDERLINE = 4;

NS_TERMCOLOR_END
