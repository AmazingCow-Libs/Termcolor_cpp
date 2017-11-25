##~---------------------------------------------------------------------------##
##                     _______  _______  _______  _     _                     ##
##                    |   _   ||       ||       || | _ | |                    ##
##                    |  |_|  ||       ||   _   || || || |                    ##
##                    |       ||       ||  | |  ||       |                    ##
##                    |       ||      _||  |_|  ||       |                    ##
##                    |   _   ||     |_ |       ||   _   |                    ##
##                    |__| |__||_______||_______||__| |__|                    ##
##                             www.amazingcow.com                             ##
##  File      : Makefile                                                      ##
##  Project   : libtermcolor                                                  ##
##  Date      : Mar 22, 2016                                                  ##
##  License   : GPLv3                                                         ##
##  Author    : n2omatt <n2omatt@amazingcow.com>                              ##
##  Copyright : AmazingCow - 2016, 2017                                       ##
##                                                                            ##
##  Description :                                                             ##
##                                                                            ##
##---------------------------------------------------------------------------~##

##------------------------------------------------------------------------------
## Create the object files and the executable test
all: obj bin

##------------------------------------------------------------------------------
## Clean up the stuff generate by obj and bin targets.
clean:
	rm -rf ./obj
	rm -rf ./bin

##------------------------------------------------------------------------------
## Create the object files for termcolor.
obj:
	mkdir -p ./obj

	g++ -std=c++11 \
		-c `find ./termcolor -iname "*.cpp"`;

	mv *.o ./obj/

##------------------------------------------------------------------------------
## Create a test executable
bin:
	mkdir -p ./bin

	g++ -std=c++11                                       \
		-D AMAZINGCOW_LIBTERMCOLOR_SHOWCASE_TEST_ENABLED \
		`find ./termcolor -iname "*.cpp"`                \
		./test/main.cpp                                  \
		-o ./bin/test
