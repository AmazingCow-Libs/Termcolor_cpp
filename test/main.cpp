//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : main.cpp                                                      //
//  Project   : libtermcolor                                                  //
//  Date      : Nov 17, 2015                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

//------------------------------------------------------------------------------
// THIS IS SHOW CASE PROGRAM - MOST USERS WILL NOT NEEDED THIS, BUT TO
// PREVENT THE HASSLE OF DELETE IT WE ADD A (HOPEFULLY) GUARD TO PREVENT
// ACCIDENTAL USAGE.
#ifdef AMAZINGCOW_LIBTERMCOLOR_SHOWCASE_TEST_ENABLED

#include <iostream>
#include "../termcolor/termcolor.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////
// Colored Function Tests                                                     //
////////////////////////////////////////////////////////////////////////////////
void test_colored_basic_colors()
{
    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test basic colors (colored function):" << endl;
    cout << termcolor::colored("Grey color"   , termcolor::GREY   ) << endl;
    cout << termcolor::colored("Red color"    , termcolor::RED    ) << endl;
    cout << termcolor::colored("Green color"  , termcolor::GREEN  ) << endl;
    cout << termcolor::colored("Yellow color" , termcolor::YELLOW ) << endl;
    cout << termcolor::colored("Blue color"   , termcolor::BLUE   ) << endl;
    cout << termcolor::colored("Magenta color", termcolor::MAGENTA) << endl;
    cout << termcolor::colored("Cyan color"   , termcolor::CYAN   ) << endl;
    cout << termcolor::colored("White color"  , termcolor::WHITE  ) << endl;

}
void test_colored_highlights()
{

    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test highlights (colored function):" << endl;

    cout << termcolor::colored("On grey color"   , termcolor::NONE, termcolor::ON_GREY   ) << endl;
    cout << termcolor::colored("On red color"    , termcolor::NONE, termcolor::ON_RED    ) << endl;
    cout << termcolor::colored("On green color"  , termcolor::NONE, termcolor::ON_GREEN  ) << endl;
    cout << termcolor::colored("On yellow color" , termcolor::NONE, termcolor::ON_YELLOW ) << endl;
    cout << termcolor::colored("On blue color"   , termcolor::NONE, termcolor::ON_BLUE   ) << endl;
    cout << termcolor::colored("On magenta color", termcolor::NONE, termcolor::ON_MAGENTA) << endl;
    cout << termcolor::colored("On cyan color"   , termcolor::NONE, termcolor::ON_CYAN   ) << endl;
    cout << termcolor::colored("On white color"  , termcolor::NONE, termcolor::ON_WHITE  ) << endl;

}
void test_colored_attributes()
{
    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test attributes (colored function):" << endl;

    cout << termcolor::colored("Bold grey color",
                               termcolor::GREY,
                               termcolor::NONE,
                               {termcolor::BOLD}) << endl;

    cout << termcolor::colored("Dark red color",
                               termcolor::RED,
                               termcolor::NONE,
                               {termcolor::DARK}) << endl;

    cout << termcolor::colored("Underline green color",
                               termcolor::GREEN,
                               termcolor::NONE,
                               {termcolor::UNDERLINE}) << endl;

    cout << termcolor::colored("Blink yellow color",
                               termcolor::YELLOW,
                               termcolor::NONE,
                               {termcolor::BLINK}) << endl;

    cout << termcolor::colored("Reversed blue color",
                               termcolor::BLUE,
                               termcolor::NONE,
                               {termcolor::REVERSE}) << endl;

    cout << termcolor::colored("Concealed Magenta color",
                               termcolor::MAGENTA,
                               termcolor::NONE,
                               {termcolor::CONCEALED}) << endl;

    cout << termcolor::colored("Bold underline reverse cyan color",
                               termcolor::CYAN,
                               termcolor::NONE,
                               {termcolor::BOLD,
                                termcolor::UNDERLINE,
                                termcolor::REVERSE}) << endl;

    cout << termcolor::colored("Dark blink concealed white color" ,
                               termcolor::WHITE,
                               termcolor::NONE,
                               {termcolor::DARK,
                                termcolor::BLINK,
                                termcolor::CONCEALED}) << endl;
}
void test_colored_mixings()
{

    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test mixing (colored function):" << endl;

    cout << termcolor::colored("Underline red on grey color",
                               termcolor::RED,
                               termcolor::ON_GREY,
                               {termcolor::UNDERLINE}) << endl;

    cout << termcolor::colored("Reversed green on red color",
                               termcolor::GREEN,
                               termcolor::ON_RED,
                               {termcolor::REVERSE}) << endl;

}


////////////////////////////////////////////////////////////////////////////////
// Colored Function Tests                                                     //
////////////////////////////////////////////////////////////////////////////////
void test_stream_basic_colors()
{
    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test basic colors (stream):" << endl;
    cout << termcolor::grey    << "Grey color"   << termcolor::reset << endl;
    cout << termcolor::red     << "Red color"    << termcolor::reset << endl;
    cout << termcolor::green   << "Green color"  << termcolor::reset << endl;
    cout << termcolor::yellow  << "Yellow color" << termcolor::reset << endl;
    cout << termcolor::blue    << "Blue color"   << termcolor::reset << endl;
    cout << termcolor::magenta << "Magenta color"<< termcolor::reset << endl;
    cout << termcolor::cyan    << "Cyan color"   << termcolor::reset << endl;
    cout << termcolor::white   << "White color"  << termcolor::reset << endl;

}
void test_stream_highlights()
{

    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test highlights (stream):" << endl;

    cout << termcolor::on_grey    << "On grey color"    << termcolor::reset << endl;
    cout << termcolor::on_red     << "On red color"     << termcolor::reset << endl;
    cout << termcolor::on_green   << "On green color"   << termcolor::reset << endl;
    cout << termcolor::on_yellow  << "On yellow color"  << termcolor::reset << endl;
    cout << termcolor::on_blue    << "On blue color"    << termcolor::reset << endl;
    cout << termcolor::on_magenta << "On magenta color" << termcolor::reset << endl;
    cout << termcolor::on_cyan    << "On cyan color"    << termcolor::reset << endl;
    cout << termcolor::on_white   << "On white color"   << termcolor::reset << endl;

}
void test_stream_attributes()
{
    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test attributes: (stream)" << endl;

    cout << termcolor::grey << termcolor::bold
         << "Bold grey color"
         << termcolor::reset << endl;

    cout << termcolor::red << termcolor::dark
         << "Dark red color"
         << termcolor::reset << endl;

    cout << termcolor::green << termcolor::underline
         << "Underline green color"
         << termcolor::reset << endl;

    cout << termcolor::yellow << termcolor::blink
         << "Blink yellow color"
         << termcolor::reset << endl;

    cout << termcolor::blue << termcolor::reverse
         << "Reversed blue color"
         << termcolor::reset << endl;

    cout << termcolor::magenta << termcolor::concealed
         << "Concealed Magenta color"
         << termcolor::reset << endl;

    cout << termcolor::cyan
         << termcolor::bold << termcolor::underline << termcolor::reverse
         << "Bold underline reverse cyan color"
         << termcolor::reset << endl;

    cout << termcolor::white
         << termcolor::dark << termcolor::blink << termcolor::concealed
         << "Dark blink concealed white color"
         << termcolor::reset << endl;

}
void test_stream_mixings()
{

    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test mixing (stream):" << endl;

    cout << termcolor::red << termcolor::on_grey << termcolor::underline
         << "Underline red on grey color"
         << termcolor::reset << endl;

    cout << termcolor::green << termcolor::on_red << termcolor::reverse
         << "Reversed green on red color"
         << termcolor::reset << endl;
}


////////////////////////////////////////////////////////////////////////////////
// Colored Function Tests                                                     //
////////////////////////////////////////////////////////////////////////////////
void test_functor_basic_colors()
{
    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test basic colors (functor):" << endl;

    auto grey_color    = termcolor::Color(termcolor::GREY   );
    auto red_color     = termcolor::Color(termcolor::RED    );
    auto green_color   = termcolor::Color(termcolor::GREEN  );
    auto yellow_color  = termcolor::Color(termcolor::YELLOW );
    auto blue_color    = termcolor::Color(termcolor::BLUE   );
    auto magenta_color = termcolor::Color(termcolor::MAGENTA);
    auto cyan_color    = termcolor::Color(termcolor::CYAN   );
    auto white_color   = termcolor::Color(termcolor::WHITE  );

    cout << grey_color   ("Grey color"   ) << endl;
    cout << red_color    ("Red color"    ) << endl;
    cout << green_color  ("Green color"  ) << endl;
    cout << yellow_color ("Yellow color" ) << endl;
    cout << blue_color   ("Blue color"   ) << endl;
    cout << magenta_color("Magenta color") << endl;
    cout << cyan_color   ("Cyan color"   ) << endl;
    cout << white_color  ("White color"  ) << endl;

}
void test_functor_highlights()
{

    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test highlights (functor):" << endl;

    auto on_grey_color    = termcolor::Color(termcolor::NONE, termcolor::ON_GREY   );
    auto on_red_color     = termcolor::Color(termcolor::NONE, termcolor::ON_RED    );
    auto on_green_color   = termcolor::Color(termcolor::NONE, termcolor::ON_GREEN  );
    auto on_yellow_color  = termcolor::Color(termcolor::NONE, termcolor::ON_YELLOW );
    auto on_blue_color    = termcolor::Color(termcolor::NONE, termcolor::ON_BLUE   );
    auto on_magenta_color = termcolor::Color(termcolor::NONE, termcolor::ON_MAGENTA);
    auto on_cyan_color    = termcolor::Color(termcolor::NONE, termcolor::ON_CYAN   );
    auto on_white_color   = termcolor::Color(termcolor::NONE, termcolor::ON_WHITE  );

    cout << on_grey_color   ("On grey color"   ) << endl;
    cout << on_red_color    ("On red color"    ) << endl;
    cout << on_green_color  ("On green color"  ) << endl;
    cout << on_yellow_color ("On yellow color" ) << endl;
    cout << on_blue_color   ("On blue color"   ) << endl;
    cout << on_magenta_color("On magenta color") << endl;
    cout << on_cyan_color   ("On cyan color"   ) << endl;
    cout << on_white_color  ("On white color"  ) << endl;

}
void test_functor_attributes()
{
    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test attributes (functor):" << endl;


    auto bold_grey_color = termcolor::Color(termcolor::GREY,
                                              termcolor::NONE,
                                              {termcolor::BOLD});

    auto dark_red_color = termcolor::Color(termcolor::RED,
                                             termcolor::NONE,
                                             {termcolor::DARK});

    auto underline_green_color = termcolor::Color(termcolor::GREEN,
                                                    termcolor::NONE,
                                                    {termcolor::UNDERLINE});

    auto blink_yellow_color = termcolor::Color(termcolor::YELLOW,
                                                 termcolor::NONE,
                                                 {termcolor::BLINK});

    auto reversed_blue_color = termcolor::Color(termcolor::BLUE,
                                                  termcolor::NONE,
                                                  {termcolor::REVERSE});

    auto concealed_magenta_color = termcolor::Color(termcolor::MAGENTA,
                                                      termcolor::NONE,
                                                      {termcolor::CONCEALED});

    auto bold_underline_reverse_cyan_color = termcolor::Color(termcolor::CYAN,
                                                                termcolor::NONE,
                                                                {termcolor::BOLD,
                                                                termcolor::UNDERLINE,
                                                                termcolor::REVERSE});

    auto dark_blink_concealed_white_color = termcolor::Color(termcolor::WHITE,
                                                               termcolor::NONE,
                                                               {termcolor::DARK,
                                                               termcolor::BLINK,
                                                               termcolor::CONCEALED});

  cout << bold_grey_color                  ("Bold grey color"                  ) << endl;
  cout << dark_red_color                   ("Dark red color"                   ) << endl;
  cout << underline_green_color            ("Underline green color"            ) << endl;
  cout << blink_yellow_color               ("Blink yellow color"               ) << endl;
  cout << reversed_blue_color              ("Reversed blue color"              ) << endl;
  cout << concealed_magenta_color          ("Concealed magenta color"          ) << endl;
  cout << bold_underline_reverse_cyan_color("Bold underline reverse cyan color") << endl;
  cout << dark_blink_concealed_white_color ("Dark blink concealed white color" ) << endl;

}
void test_functor_mixings()
{

    cout << "-----------------------------------------------------------------" << endl;

    cout << "Test mixing (functor):" << endl;

    auto underline_red_on_grey_color = termcolor::Color(termcolor::RED,
                                                          termcolor::ON_GREY,
                                                          {termcolor::UNDERLINE});

    auto reversed_green_on_red_color = termcolor::Color(termcolor::GREEN,
                                                          termcolor::ON_RED,
                                                          {termcolor::REVERSE});

    cout << underline_red_on_grey_color("Underline red on grey color") << endl;
    cout << reversed_green_on_red_color("Reversed green on red color") << endl;
}

int main(int argc, const char * argv[])
{
    int option = 0;
    if(argc > 1)
        option = atoi(argv[1]);

    termcolor::Config::colorMode = static_cast<termcolor::Config::ColorMode>(option);

    test_colored_basic_colors();
    test_colored_highlights  ();
    test_colored_attributes  ();
    test_colored_mixings     ();

    test_stream_basic_colors();
    test_stream_highlights  ();
    test_stream_attributes  ();
    test_stream_mixings     ();

    test_functor_basic_colors();
    test_functor_highlights  ();
    test_functor_attributes  ();
    test_stream_mixings      ();


    cout << "Foreground sequences:" << endl;
    for(auto i = termcolor::GREY; i <= termcolor::WHITE; ++i)
    {
        cout << termcolor::codeToString(i)
             << " test "
             << termcolor::codeToString(termcolor::RESET)
             << endl;
    }


    cout << "Background sequences:" << endl;
    for(auto i = termcolor::ON_GREY; i <= termcolor::ON_WHITE; ++i)
    {
        cout << termcolor::codeToString(i)
             << " test "
             << termcolor::codeToString(termcolor::RESET)
             << endl;
    }

    cout << "Attributes sequences:" << endl;
    cout << termcolor::codeToString(termcolor::BLINK)
         << " test "
         << termcolor::codeToString(termcolor::RESET)
         << endl;

    cout << termcolor::codeToString(termcolor::BOLD)
         << " test "
         << termcolor::codeToString(termcolor::RESET)
         << endl;

    cout << termcolor::codeToString(termcolor::CONCEALED)
         << " test "
         << termcolor::codeToString(termcolor::RESET)
         << endl;

    cout << termcolor::codeToString(termcolor::DARK)
         << " test "
         << termcolor::codeToString(termcolor::RESET)
         << endl;

    cout << termcolor::codeToString(termcolor::REVERSE)
         << " test "
         << termcolor::codeToString(termcolor::RESET)
         << endl;

    cout << termcolor::codeToString(termcolor::UNDERLINE)
         << " test "
         << termcolor::codeToString(termcolor::RESET)
         << endl;


    return 0;
}
#endif // AMAZINGCOW_LIBTERMCOLOR_SHOWCASE_TEST_ENABLED //
