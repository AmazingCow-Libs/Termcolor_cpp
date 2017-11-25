//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Functions.h                                                   //
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

// std
#include <string>
#include <vector>
// libtermcolor
#include "termcolor_Utils.h"
#include "Constants.h"


NS_TERMCOLOR_BEGIN

//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
///@brief
///  Constructs the escape string sequence.
///@param code
///  The escape code integer.\n
///  It won't check for code validity. Is users responsabillity
///  to ensure that code is valid. So the safer use is with one
///  termcolor constants.
///@returns
///  A escape sequence in format of "\033[Xm",
///  where X is the code given as argument.
std::string codeToString(int code);


//----------------------------------------------------------------------------//
// Stream Functions                                                           //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Foreground Colors.
///@brief Put the grey foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& grey(std::ostream &os);

///@brief Put the red foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& red(std::ostream &os);

///@brief Put the green foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& green(std::ostream &os);

///@brief Put the yellow foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& yellow(std::ostream &os);

///@brief Put the blue foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& blue(std::ostream &os);

///@brief Put the magenta foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& magenta(std::ostream &os);

///@brief Put the cyan foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& cyan(std::ostream &os);

///@brief Put the white foreground escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& white(std::ostream &os);

//------------------------------------------------------------------------------
// Background Colors.
///@brief Put the grey background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_grey(std::ostream &os);

///@brief Put the red background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_red(std::ostream &os);

///@brief Put the green background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_green(std::ostream &os);

///@brief Put the yellow background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_yellow(std::ostream &os);

///@brief Put the blue background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_blue(std::ostream &os);

///@brief Put the magenta background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_magenta(std::ostream &os);

///@brief Put the cyan background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_cyan(std::ostream &os);

///@brief Put the white background escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& on_white(std::ostream &os);

//------------------------------------------------------------------------------
// Attributes.
///@brief Put the blink attribute escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& blink(std::ostream &os);

///@brief Put the bold attribute escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& bold(std::ostream &os);

///@brief Put the concealed attribute escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& concealed(std::ostream &os);

///@brief Put the dark attribute escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& dark(std::ostream &os);

///@brief Put the reverse attribute escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& reverse(std::ostream &os);

///@brief Put the underline attribute escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& underline(std::ostream &os);

//------------------------------------------------------------------------------
// Reset.
///@brief Put the reset escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& reset(std::ostream &os);


//----------------------------------------------------------------------------//
// Colored                                                                    //
//----------------------------------------------------------------------------//
///@brief
///  Builds the colored output in one function. \n
///  It will put the foreground color, then the background and after all
///  the attributes if there are any.
///@param str
///  The string that will be colored.
///@param foreground
///  A valid foreground color code. (Mandatory)
///@param background
///  A valid background color code. (Optional)
///@param attributes
///  A valid attributes codes. (Optional)
///@note
///  This function is affected by the value of Config.colorMode.
///@warning
///  This function will not check the validity of the color codes,
///  so is user's responsibility to ensure that them are valid. \n
///  The best bet is use the termcolor constants.
std::string colored(
    const std::string      &str,
    int                     foreground,
    int                     background = termcolor::NONE,
    const std::vector<int> &attributes = std::vector<int>());

NS_TERMCOLOR_END
