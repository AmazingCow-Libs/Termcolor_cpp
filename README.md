# Termcolor_cpp

**Made with <3 by [Amazing Cow](http://www.amazingcow.com).**



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Websites:

* [Termcolor_cpp Website](http://opensource.amazingcow.com/libs/termcolor_cpp/)
* [Libs Website](http://opensource.amazingcow.com/libs/) - 
The Amazing Cow's Libs site.


<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Description:

```Termcolor_cpp``` is a library to ease the terminal coloring.    
It was inspired by the python's termcolor.


#### With ```Termcolor_cpp``` we can:

* Use the colored function - Ex: ```colored("MyString", RED, ON_BLUE, {BLINK});```
* Use streams - Like ```cout << on_yellow << red << "MyString" << reset;```
* Use functor objects - This is nice because we can setup the coloring options
and use it later, possible multiple times.


#### Smart coloring:

What is really nice in ```Termcolor_cpp``` and in [cowtermcolor_py](http://www.github.com/AmazingCow-Libs/cowtermcolor_py)
is both libs _knows_ if the output is the terminal or not,  i.e. them knows
if the ```stdout``` is attached to a ```tty```.

And what we gain with this?

1. By default it will output the coloring escape sequences only if the ```stdout```
is a ```tty```.
2. Cleaner code - We don't need check the output anymore (If we want the default).
3. More cleaner code - To enable, or disable the coloring we can set it only once.

For example, let's imagine that you have an program that output the colors in 
terminal. So far, so good, but what is gonna happen if the user redirects it
to a file?

``` 
$ your-awesome-app > file.txt
$ less file.txt

#Output by less... (Imagine, that this was the output of your app ;p)
ESC[31mColors play nice with terminalESC[0m
ESC[31mColors doesn't like files :DESC[0m
```

As you see, the terminal colors are just a string that has some meaning to the 
terminal - i.e. they are escape sequences, nothing more. In a file them are
meaningless.    

**We don't want code "a lot" just to handle this case.**

So let the lib handle this for us... (Of course we have a way to override this
if we want to).

In ```Termcolor_cpp``` we have the ```Config::colorMode``` module 
object that defines the desired behavior.   
For default it is ```Config::ColorMode::OnlyIfTerminal```, but can be 
others values too (check the [examples](#Examples:) section).

So the lib will check the type of the output and put colors correctly :D


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



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Examples:

There are some examples in ```Termcolor_cpp``` file, but here is a brief
usage of ```Termcolor_cpp```:

### Colored function:
 
``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
   //This is very similar from python-termcolor... 
   cout << termcolor::colored("[FATAL]", termcolor::RED)
        << "- Path is invalid ("
        << termcolor::colored(path, termcolor::MAGENTA)
        << ")";
    exit(1);
```
  

### Stream:

``` c++
#include "termcolor/termcolor.h"

void f(const std::string &path)
{
   //In C++ we think that the streams are the most easy way to use it.
   cout << termcolor::red     << "[FATAL]" 
        << termcolor::reset   << "- Path is invalid ("
        << termcolor::magenta << path 
        << termcolor::reset   << "(" 
        << endl;
    exit(1);
```
 
### Functors:
 
 ``` c++
 #include "termcolor/termcolor.h"
 
 void f(const std::string &path)
 {
    //Functions are great because it "holds" the information about 
    //the coloring options, so it can be passed as arguments to functions,
    //be used multiple times, etc.
    auto red_color     = termcolor::options(termcolor::RED);
    auto magenta_color = termcolor::options(termcolor::MAGENTA);

    cout << red_color("[FATAL]") 
         << " - Path is invalid ("
         << magenta_color(path) 
         << ")"
         << endl;
    exit(1);
```

### Controlling the Coloring options:

The ```Config::colorMode``` defines the behavior of coloring in
```Termcolor_cpp``` .

It has the following _constants_ that can be used:

* ```Config::ColorMode::OnlyIfTerminal``` - Color escapes codes are only put 
into the  strings/streams if the ```os.stdout``` is assigned to a ```tty```.
* ```Config::ColorMode::Always``` - Don't care for where the ```os.stdout``` 
is assigned. Put the coloring escape sequences anyway.
* ```Config::ColorMode::Never``` - Don't care for where the ```os.stdout``` 
is assigned. **DO NOT** put the coloring escape sequences anyway.


So let's write a simple program to check this:

#### Only put colors if the stdout is the tty.

```c++
#include "termcolor/termcolor.h"

//Note that we don't need to do anything, because Config::ColorMode::OnlyIfTerminal
//is the default, but we of course can be explicit if we want...

Config::colorMode = Config::ColorMode::ONLY_IF_TERMINAL;
cout << green << "Only in Terminal" << reset << endl
```

#### Put colors ALWAYS.

```c++
#include "termcolor/termcolor.h"

//This will output colors always - This is not default behavior so 
//we NEED to be explicit here.
ColorMode::colorMode = Config::ColorMode::Always;
cout << green << "I will mess the output if I'm went to a file" 
     << reset << endl;
```

#### Put colors NEVER.

```c++
#include "termcolor/termcolor.h"

//This will output colors never - This is not default behavior so 
//we NEED to be explicit here.
ColorMode::colorMode = Config::ColorMode::Never;
cout <<  green << "I'm never colored :/" <<  reset << endl;
```



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Documentation:

We strive to make our source code fully documented.   
While there are a myriad of comments, one might find useful take a look at:

* [Project Website](http://opensource.amazingcow.com/libs/termcolor_cpp/).
* [Doxgen Docs](http://opensource.amazingcow.com/libs/termcolor_cpp/doxygen/).
* [A list of blog posts about the project](http://opensource.amazingcow.com/libs/termcolor_cpp/posts/).

Anyway if you didn't understand something let us know sending a mail to  
[help_opensource@amazingcow.com]() with the subject filled with the
name of this repo.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Dependencies:

* There is no dependency for **termcolor_cpp**



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## License:

This software is released under GPLv3.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## TODO:

Check the TODO file for general things.

This projects uses the COWTODO tags.   
So install [cowtodo](http://www.github.com/AmazingCow-Tools/COWTODO) and run:

``` bash
$ cd path/to/the/project
$ cowtodo 
```

That's gonna give you all things to do :D.



<!-- ####################################################################### -->
<!-- ####################################################################### -->

## Others:

Check our repos and take a look at our 
[open source site](http://opensource.amazingcow.com).
