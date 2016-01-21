Termcolor_cpp
====

Made with <3 by [Amazing Cow](http://www.amazingcow.com).

### Intro

This lib is a loosely clone of [python-termcolor](), an amazing python package 
that ease in several orders of magnitude the process of adding colored output in
terminals.

You can read a post by [n2omatt](http://n2omatt.github.io) about the benefits 
of coloring output - 
[Termcolor - A very cool output coloring package for python.](https://n2omatt.github.io/programming/2015/11/08/python-package-termcolor.html)

### Motivation

The python-termcolor is amazing - simply amazing - it helps a lot creating cool
cli programs and its usage is very intuitive and powerful.

An example:
``` python
import termcolor;

#Some stuf...

print "{} - Path is invalid ({})".format(termcolor.colored("[FATAL]", "red"),
                                         termcolor.colored(path, "magenta");

```

But we do a lot of C++ too and would be very nice do this kind of stuff in it.   
So we decide to create our own clone of python-termcolor.


### Termcolor_cpp

Instead of being a 1:1 clone (this isn't even possible) we decide to add features
that we think that is very useful. So while the overall idea is the same, the 
```termcolor_cpp``` has a lot of other ways to acomplish the same goal.

We can:

* Use the colored function - _"Same"_ as the python-termcolor colored function.
* Use stream modifiers - Like the std::hex, std::setw, etc...
* Use functor objects - This is nice because we can setup the coloring options 
and use it later, possible multiple times.


### Installation

This lib is only two file (three counting the test file), so is very easy to 
setup in various different scenarios.   

The most basic usage is:

1. Download the package (or ```git clone``` it).
2. Grab the ```termcolor``` folder and put it onto the desired place.
3. Setup your compiler include paths (```g++ -I/path/for/termcolor ...``` ).
4. Include it and use... :)

### Usage

Please check out the ```test/main.cpp``` for examples - Notice that this examples
are very, very based on the python-termcolor examples.

Here is very simple usage options:

##### Colored function:

``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
    //Like our first example in python...
    cout << termcolor::colored("[FATAL]", termcolor::RED) 
         << "- Path is invalid ("
         << termcolor::colored(path, termcolor::MAGENTA)
         << ")." << endl;
}

```


##### Stream :

``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
    //Like our first example in python...
    cout << termcolor::red << "[FATAL]" << termcolor::reset 
         << "- Path is invalid ("
         << termcolor::magenta << path << termcolor::reset
         << ")." << endl;
}

```

##### Functors :

``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
    //Like our first example in python...
    auto red_color     = termcolor::options(termcolor::RED);
    auto magenta_color = termcolor::options(termcolor::MAGENTA);

    cout << red_color("[FATAL]")
         << "- Path is invalid ("
         << magenta_color(path) 
         << ")." << endl;
}

```

## License:
This software is released under GPLv3.

## TODO:
Check the TODO file.

## Others:
Check our repos and take a look at our [open source site](http://opensource.amazingcow.com).
