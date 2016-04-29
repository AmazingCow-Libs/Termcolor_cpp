# Termcolor_cpp

**Made with <3 by [Amazing Cow](http://www.amazingcow.com).**


<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Project website:

[opensource.amazingcow.com/libs/termcolor_cpp](http:/opensource.amazingcow/libs/termcolor_cpp)



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Description:

```Termcolor_cpp``` is a library to ease the terminal coloring.    
It was inspired by the **amazing** python's [termcolor]().

With ```Termcolor_cpp``` we can:

* Use the colored function - _"Same"_ as the python-termcolor colored function.
* Use stream modifiers - Like the std::hex, std::setw, etc...
* Use functor objects - This is nice because we can setup the coloring options
and use it later, possible multiple times.


### Motivation:

We do a lot of C++, we do a lot of python and for all _terminal coloring_ libs
that we mess with in python we think that ```termcolor``` is the most pleasing 
one to work with.    
Unfortunately, we didn't found anything similar for C++ - So why not try
to create one based in ```termcolor``` but adding some stuff that we think
that would be great for C++?

We hope that you enjoy :D


<br>

As usual, you are **very welcomed** to **share** and **hack** it.


## Examples:

### Colored function:

``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
    //This is very similar from python-termcolor... 
    cout << termcolor::colored("[FATAL]", termcolor::RED)
         << "- Path is invalid ("
         << termcolor::colored(path, termcolor::MAGENTA)
         << ")." << endl;
}

```


### Stream:

``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
    //In C++ we think that the streams are the most easy way to use it.
    cout << termcolor::red << "[FATAL]" << termcolor::reset
         << "- Path is invalid ("
         << termcolor::magenta << path << termcolor::reset
         << ")." << endl;
}

```

### Functors:

``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
    //Functions are great because it "holds" the information about 
    //the coloring options, so it can be passed as arguments to functions,
    //be used multiple times, etc.
    auto red_color     = termcolor::Color(termcolor::RED);
    auto magenta_color = termcolor::Color(termcolor::MAGENTA);

    cout << red_color("[FATAL]")
         << "- Path is invalid ("
         << magenta_color(path)
         << ")." << endl;
}

```


<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Documentation:

We strive to make our source code fully documented.   
While there are a myriad of comments, one might find useful take a look at:

* [Doxygen Docs]()
* [Project Website]()
* [A list of blog posts about the project]()



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Dependencies:

There is no dependency for ```Termcolor_cpp```.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## License:

This software is released under GPLv3.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## TODO:

Check the TODO file for general things.

This projects uses the COWTODO tags.   
So install [cowtodo](https://github.com/AmazingCow-Tools/COWTODO/) and run:

``` bash
$ cd path/for/the/project
$ cowtodo 
```

That's gonna give you all things to do :D.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## BUGS:

We strive to make all our code the most bug-free as possible - But we know 
that few of them can pass without we notice ;).

Please if you find any bug report to [bugs_opensource@amazingcow.com]() 
with the name of this project and/or create an issue here in Github.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## See also:
    
* [cowtermcolor_py](https://www.github.com/AmazingCow-Libs/cowtermcolor_py) -
A more robust package than ```termcolor``` for python.    
Have a lot of inspiration from this lib but has other intersting features too.


<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Others:
Check our repos and take a look at our [open source site](http://opensource.amazingcow.com).
