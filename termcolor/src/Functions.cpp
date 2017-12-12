//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Functions.cpp                                                 //
//  Project   : libtermcolor                                                  //
//  Date      : Nov 24, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../include/Functions.h"
// C
#include <unistd.h>
// std
#include <cstdio>
#include <sstream>
// libtermcolor
#include "../include/Config.h"

// Usings
USING_NS_TERMCOLOR;


//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
constexpr auto kStartEscape = "\033[";
constexpr auto kEndEscape   = "m";
constexpr auto kResetStr    = "\033[0m";


//----------------------------------------------------------------------------//
// MACROS                                                                     //
//----------------------------------------------------------------------------//
#define _PUT(_os_, _color_)       \
    put_color((_os_), (_color_)); \
    return (_os_);


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
bool should_put_color()
{
    //--------------------------------------------------------------------------
    // Never put colors.
    if(Config::colorMode == Config::ColorMode::Never)
        return false;

    //--------------------------------------------------------------------------
    // Always put colors.
    if(Config::colorMode == Config::ColorMode::Always)
        return true;

    //--------------------------------------------------------------------------
    // Check if we're on terminal to put the colors.
    if(isatty(fileno(stdout)) == 1)
        return true;

    return false;
}

void put_color(std::ostream &os, int color)
{
    if(!should_put_color())
        return;

    os << kStartEscape << color << kEndEscape;
}


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
std::string termcolor::codeToString(int code)
{
    return kStartEscape + std::to_string(code) + kEndEscape;
}


//----------------------------------------------------------------------------//
// Stream Functions                                                           //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Foreground Colors.
std::ostream& termcolor::grey   (std::ostream &os) { _PUT(os, GREY   ); }
std::ostream& termcolor::red    (std::ostream &os) { _PUT(os, RED    ); }
std::ostream& termcolor::green  (std::ostream &os) { _PUT(os, GREEN  ); }
std::ostream& termcolor::yellow (std::ostream &os) { _PUT(os, YELLOW ); }
std::ostream& termcolor::blue   (std::ostream &os) { _PUT(os, BLUE   ); }
std::ostream& termcolor::magenta(std::ostream &os) { _PUT(os, MAGENTA); }
std::ostream& termcolor::cyan   (std::ostream &os) { _PUT(os, CYAN   ); }
std::ostream& termcolor::white  (std::ostream &os) { _PUT(os, WHITE  ); }

//------------------------------------------------------------------------------
// Background Colors.
std::ostream& termcolor::on_grey   (std::ostream &os) { _PUT(os, ON_GREY   ); }
std::ostream& termcolor::on_red    (std::ostream &os) { _PUT(os, ON_RED    ); }
std::ostream& termcolor::on_green  (std::ostream &os) { _PUT(os, ON_GREEN  ); }
std::ostream& termcolor::on_yellow (std::ostream &os) { _PUT(os, ON_YELLOW ); }
std::ostream& termcolor::on_blue   (std::ostream &os) { _PUT(os, ON_BLUE   ); }
std::ostream& termcolor::on_magenta(std::ostream &os) { _PUT(os, ON_MAGENTA); }
std::ostream& termcolor::on_cyan   (std::ostream &os) { _PUT(os, ON_CYAN   ); }
std::ostream& termcolor::on_white  (std::ostream &os) { _PUT(os, ON_WHITE  ); }

//------------------------------------------------------------------------------
// Attributes.
std::ostream& termcolor::blink    (std::ostream &os) { _PUT(os, BLINK    ); }
std::ostream& termcolor::bold     (std::ostream &os) { _PUT(os, BOLD     ); }
std::ostream& termcolor::concealed(std::ostream &os) { _PUT(os, CONCEALED); }
std::ostream& termcolor::dark     (std::ostream &os) { _PUT(os, DARK     ); }
std::ostream& termcolor::reverse  (std::ostream &os) { _PUT(os, REVERSE  ); }
std::ostream& termcolor::underline(std::ostream &os) { _PUT(os, UNDERLINE); }

//------------------------------------------------------------------------------
// Reset.
std::ostream& termcolor::reset(std::ostream &os)
{
    if(should_put_color())
        os << kResetStr;

    return os;
}

//----------------------------------------------------------------------------//
// Colored                                                                    //
//----------------------------------------------------------------------------//
std::string termcolor::colored(
    const std::string      &str,
    int                     foreground,
    int                     background,
    const std::vector<int> &attributes)
{
    //COWHACK: Check what is better...
    //COWHACK: 1 - stringstreams - Like we're doing now...
    //COWHACK: 2 - sprintf - We can calculate the array size based in the options.
    //COWHACK: 3 - String concat.
    std::stringstream ss;

    for(auto attribute : attributes)
    {
        if(attribute)
             put_color(ss, attribute);
    }

    if(background) put_color(ss, background);
    if(foreground) put_color(ss, foreground);

    ss << str;
    ss << termcolor::reset;

    return ss.str();
}
