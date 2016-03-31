//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        termcolor.cpp                             //
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

//Header
#include "termcolor.h"
//std
 #include <unistd.h>

//Usings
USING_NS_TERMCOLOR;
using namespace std;

// Config //
Config::ColorMode Config::colorMode = Config::ColorMode::Default;

// Constants //
constexpr const char *start_escape = "\033[";
constexpr const char *end_escape   = "m";
constexpr const char *reset_str    = "\033[0m";

// Helper Functions //
bool should_put_color()
{
    if(Config::colorMode == Config::ColorMode::Never)
        return false;
    else if(Config::colorMode == Config::ColorMode::Always)
        return true;

    else //if(colorMode == ColorMode::OnlyIfTerminal)
    {
        if(isatty(fileno(stdout)))
            return true;
    }

    return false;
}

void put_color(std::ostream &os, int color)
{

    if(!should_put_color())
        return;

    os << start_escape << color << end_escape;
}

////////////////////////////////////////////////////////////////////////////////
// Functions                                                                  //
////////////////////////////////////////////////////////////////////////////////
std::string termcolor::codeToString(int code)
{
    return start_escape + std::to_string(code) + end_escape;
}


////////////////////////////////////////////////////////////////////////////////
// Stream Functions                                                           //
////////////////////////////////////////////////////////////////////////////////
// Foreground Colors //
std::ostream& termcolor::grey(std::ostream &os)
{
    put_color(os, termcolor::GREY);
    return os;
}
std::ostream& termcolor::red(std::ostream &os)
{
    put_color(os, termcolor::RED);
    return os;
}
std::ostream& termcolor::green(std::ostream &os)
{
    put_color(os, termcolor::GREEN);
    return os;
}
std::ostream& termcolor::yellow(std::ostream &os)
{
    put_color(os, termcolor::YELLOW);
    return os;
}
std::ostream& termcolor::blue(std::ostream &os)
{
    put_color(os, termcolor::BLUE);
    return os;
}
std::ostream& termcolor::magenta(std::ostream &os)
{
    put_color(os, termcolor::MAGENTA);
    return os;
}
std::ostream& termcolor::cyan(std::ostream &os)
{
    put_color(os, termcolor::CYAN);
    return os;
}
std::ostream& termcolor::white(std::ostream &os)
{
    put_color(os, termcolor::WHITE);
    return os;
}

// Background Colors //
std::ostream& termcolor::on_grey(std::ostream &os)
{
    put_color(os, termcolor::ON_GREY);
    return os;
}
std::ostream& termcolor::on_red(std::ostream &os)
{
    put_color(os, termcolor::ON_RED);
    return os;
}
std::ostream& termcolor::on_green(std::ostream &os)
{
    put_color(os, termcolor::ON_GREEN);
    return os;
}
std::ostream& termcolor::on_yellow(std::ostream &os)
{
    put_color(os, termcolor::ON_YELLOW);
    return os;
}
std::ostream& termcolor::on_blue(std::ostream &os)
{
    put_color(os, termcolor::ON_BLUE);
    return os;
}
std::ostream& termcolor::on_magenta(std::ostream &os)
{
    put_color(os, termcolor::ON_MAGENTA);
    return os;
}
std::ostream& termcolor::on_cyan(std::ostream &os)
{
    put_color(os, termcolor::ON_CYAN);
    return os;
}
std::ostream& termcolor::on_white(std::ostream &os)
{
    put_color(os, termcolor::ON_WHITE);
    return os;
}

// Attributes //
std::ostream& termcolor::blink(std::ostream &os)
{
    put_color(os, termcolor::BLINK);
    return os;
}
std::ostream& termcolor::bold(std::ostream &os)
{
    put_color(os, termcolor::BOLD);
    return os;
}
std::ostream& termcolor::concealed(std::ostream &os)
{
    put_color(os, termcolor::CONCEALED);
    return os;
}
std::ostream& termcolor::dark(std::ostream &os)
{
    put_color(os, termcolor::DARK);
    return os;
}
std::ostream& termcolor::reverse(std::ostream &os)
{
    put_color(os, termcolor::REVERSE);
    return os;
}
std::ostream& termcolor::underline(std::ostream &os)
{
    put_color(os, termcolor::UNDERLINE);
    return os;
}


std::ostream& termcolor::reset(std::ostream &os)
{
    if(should_put_color())
        os << reset_str;

    return os;
}



////////////////////////////////////////////////////////////////////////////////
// Colored Function                                                           //
////////////////////////////////////////////////////////////////////////////////
std::string termcolor::colored(const std::string &str,
                               int foreground,
                               int background,
                               const std::vector<int> &attributes)
{
    //COWHACK: Check what is better...
    //COWHACK: 1 - stringstreams - Like we're doing now...
    //COWHACK: 2 - sprintf - We can calculate the array size based in the options.
    //COWHACK: 3 - String concat.
    std::stringstream ss;

    for(auto attribute : attributes)
        if(attribute)
             put_color(ss, attribute);

    if(background) put_color(ss, background);
    if(foreground) put_color(ss, foreground);

    ss << str;

    ss << termcolor::reset;

    return ss.str();
}
