//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Config.h                                                      //
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

/// @brief Global Color Modes - MODIFY ALL COLORING FUNCTIONS. \n
///   This defines how the coloring functions will behave.     \n
///   To change the behavior assign a new value to Config.colorMode.
struct Config
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
    enum class ColorMode
    {
        OnlyIfTerminal = 0, ///< Color escapes codes are only inserted if the
                            ///  stdout is assigned to a tty.
                            ///  \n
                            ///  This enables code to don't care the type of
                            ///  the stdout i.e. if a pipe, file, or tty.
                            ///  \n
                            ///  If the stdout isn't assigned to a tty all
                            ///  coloring functions won't modify the string.
                            ///  For the streams functions, them won't put
                            ///  any escape sequence in the stream.

        Always = 1, ///< Don't care for where the stdout is assigned.
                    ///  Put the coloring escape sequences anyway.

        Never = 2, ///< Don't care for where the stdout is assigned.
                   ///  DO NOT put the coloring escape sequences anyway.

        Default = OnlyIfTerminal ///< Same as OnlyIfTerminal.
    };


    //------------------------------------------------------------------------//
    // Variables                                                              //
    //------------------------------------------------------------------------//
    /// @brief
    ///   The value of colorMode will control, how the escape sequences
    ///   are used in the program. To override the current behavior assign a
    ///   new value to this variable.
    static ColorMode colorMode;


    //------------------------------------------------------------------------//
    // Makes the class acts like namespace.                                   //
    //------------------------------------------------------------------------//
     Config() = delete;
    ~Config() = delete;

    Config(const Config &)           = delete;
    Config& operator=(const Config&) = delete;

    Config(const Config &&)           = delete;
    Config& operator=(const Config&&) = delete;

}; // struct Config

NS_TERMCOLOR_END
