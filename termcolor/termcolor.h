//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        termcolor.h                               //
//            █ █        █ █        termcolor_cpp                             //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __AmazingCow_TermColor_Cpp_termcolor_h__
#define __AmazingCow_TermColor_Cpp_termcolor_h__

//std
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

// Namespace Stuff //
#define NS_TERMCOLOR_BEGIN namespace termcolor {
#define NS_TERMCOLOR_END   }
#define USING_NS_TERMCOLOR using namespace termcolor

//The core version number.
#define COW_TERMCOLOR_VERSION_MAJOR    "0"
#define COW_TERMCOLOR_VERSION_MINOR    "2"
#define COW_TERMCOLOR_VERSION_REVISION "1"

#define COW_TERMCOLOR_VERSION "0.2.1"

NS_TERMCOLOR_BEGIN

////////////////////////////////////////////////////////////////////////////////
// Constants / Enums                                                          //
////////////////////////////////////////////////////////////////////////////////
constexpr int NONE  = 0;
constexpr int RESET = 0;

// Foreground Colors //
constexpr int GREY    = 30;
constexpr int RED     = 31;
constexpr int GREEN   = 32;
constexpr int YELLOW  = 33;
constexpr int BLUE    = 34;
constexpr int MAGENTA = 35;
constexpr int CYAN    = 36;
constexpr int WHITE   = 37;

// Background Colors //
constexpr int ON_GREY    = 40;
constexpr int ON_RED     = 41;
constexpr int ON_GREEN   = 42;
constexpr int ON_YELLOW  = 43;
constexpr int ON_BLUE    = 44;
constexpr int ON_MAGENTA = 45;
constexpr int ON_CYAN    = 46;
constexpr int ON_WHITE   = 47;

// Attributes //
constexpr int BLINK     = 5;
constexpr int BOLD      = 1;
constexpr int CONCEALED = 8;
constexpr int DARK      = 2;
constexpr int REVERSE   = 7;
constexpr int UNDERLINE = 4;


////////////////////////////////////////////////////////////////////////////////
// Functions                                                                  //
////////////////////////////////////////////////////////////////////////////////
///@brief Constructs the escape string sequence.
///@param code - The escape code integer.\n
///              It won't check for code validity. Is users responsabillity
///              to ensure that code is valid. So the safer use is with one
///              termcolor constants.
///@returns A escape sequence in format of "\033[Xm",
///         where X is the code given as argument.
std::string codeToString(int code);


////////////////////////////////////////////////////////////////////////////////
// Config                                                                     //
////////////////////////////////////////////////////////////////////////////////
///@brief Global Color Modes - MODIFY ALL COLORING FUNCTIONS. \n
///This class defines how the coloring functions will behave. \n
///To change the behavior assign a new value to Config.colorMode.
class Config
{
public:
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

    ///@brief The value of colorMode will control, how the escape sequences
    ///are used in the program. To override the current behavior assign a
    ///new value to this variable.
    static ColorMode colorMode;
 };


////////////////////////////////////////////////////////////////////////////////
// Stream Functions                                                           //
////////////////////////////////////////////////////////////////////////////////
// Foreground Colors //

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


// Background Colors //

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


// Attributes //

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


// Reset //

///@brief Put the reset escape sequence in the stream.
///@note This function is affected by the value of Config.colorMode
std::ostream& reset(std::ostream &os);


////////////////////////////////////////////////////////////////////////////////
// Colored Function                                                           //
////////////////////////////////////////////////////////////////////////////////
///@brief Builds the colored output in one function. \n
///       It will put the foreground color, then the background and after all
///       the attributes if there are any.
///@param str - The string that will be colored.
///@param foreground - A valid foreground color code. (Mandatory)
///@param background - A valid background color code. (Optional)
///@param attributes - A valid attributes codes. (Optional)
///@note This function is affected by the value of Config.colorMode.
///@warning This function will not check the validity of the color codes,
///so is user's responsibility to ensure that them are valid. \n
///The best bet is use the termcolor constants.
std::string colored(const std::string &str,
                    int foreground,
                    int background = termcolor::NONE,
                    const std::vector<int> &attributes = std::vector<int>());


////////////////////////////////////////////////////////////////////////////////
// Functor Class                                                              //
////////////////////////////////////////////////////////////////////////////////
///
class options
{
public:
    options(int foreground,
          int background = termcolor::NONE,
          const std::vector<int> &attributes = std::vector<int>()) :
        m_foreground(foreground),
        m_background(background),
        m_attributes(attributes)
    {
        //Empty...
    }

    std::string operator ()(const std::string &str)
    {
        return termcolor::colored(str, m_foreground, m_background, m_attributes);
    }

private:
    int              m_foreground;
    int              m_background;
    std::vector<int> m_attributes;
};




NS_TERMCOLOR_END
#endif // defined(__AmazingCow_TermColor_Cpp_termcolor_h__) //
