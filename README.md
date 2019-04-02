# HashParser
C++ Configuration files Parser

Prerequisite:
-gcc compiler
-linux-based OS (tested on Ubuntu) or Windows


Build instructions:
-open a terminal(bash or cmd)
-navigate to project src folder
-Windows: run: cd ../ && mkdir build && cd src && g++ -g -o ../build/ConfigurationParser ConfigParser.cpp main.cpp
-Linux: run g++ -g -o ../build/ConfigurationParser ConfigParser.cpp main.cpp

Usage:
-give a .ini file's path when running the executable and the tool will import every property-value pair to its internal data structure(unordered_map)
or hardcode it(not recommended) in ConfigParser() constructor call
-take advantage of this and use those properties for your customizable projects

E.G.:
#include "../include/ConfigParser.hpp"
using namespace HashParser;

int main(int argc, char** argv){

    ConfigParser parser("../testToParse.ini"); /* or give it as commandLine argument */
    parser.parse();
    std::cout<<parser; /* print all the properties and their values */
    std::string value = parser.GetConfigValue("server");
    std::cout<<value;
    return 0;
}

Advice: Build the project as a static/dynamic library and use it in your projects