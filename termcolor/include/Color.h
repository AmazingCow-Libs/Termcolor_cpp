//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Color.h                                                       //
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
#include "Constants.h"
#include "Functions.h"


NS_TERMCOLOR_BEGIN

///@brief
///  Holds a set of coloring parameters into a nice object. \n
///  This enables you group a set of different parameters
///  and reuse them with ease.
///@code
///  For Example:
///     auto greyOnRedBlinking      = Color(GREY, RED, {BLINK});
///     auto redOnBlueBoldUnderline = Color(GREY, RED, {BOLD, UNDERLINE});
///
///     cout << greyOnRedBlinking      ("Hi there..."   ) << endl;
///     cout << redOnBlueBoldUnderline ("I <3 termcolor") << endl;
///@endcode
class Color
{
public:
    ///@brief
    //   Basic constructor.
    ///@param foreground
    ///  A valid foreground color code. (Mandatory)
    ///@param background
    ///  A valid background color code. (Optional)
    ///@param attributes
    ///  A valid attributes codes. (Optional)
    ///@warning
    ///  This function will not check the validity of the color codes,
    ///  so is user's responsibility to ensure that them are valid. \n
    ///  The best bet is use the termcolor constants.
    Color(
        int                     foreground,
        int                     background = termcolor::NONE,
        const std::vector<int> &attributes = std::vector<int>()) :
        // Members.
        m_foreground(foreground),
        m_background(background),
        m_attributes(attributes)
    {
        // Empty...
    }

    //------------------------------------------------------------------------//
    // Operator Overloads                                                     //
    //------------------------------------------------------------------------//
    ///@brief Makes the object callable - It will apply
    ///       the foreground colors, next the background colors
    ///       and after that the attributes.
    ///@param str - The string that will be colored.
    ///@note This function is affected by the value of Config.colorMode.
    std::string operator ()(const std::string &str)
    {
        return termcolor::colored(
            str,
            m_foreground,
            m_background,
            m_attributes
        );
    }

    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
private:
    int              m_foreground;
    int              m_background;
    std::vector<int> m_attributes;

}; // class Color
NS_TERMCOLOR_END
