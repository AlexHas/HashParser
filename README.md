# HashParser
C++ Configuration files Parser

Prerequisite:
-gcc compiler
-linux-based OS (tested on Ubuntu) or Windows


Build instructions:
-open a terminal(bash or cmd)
-navigate to project src folder
-Windows: run: cd ../ && mkdir build && cd src && g++ -g -o ../build/ConfigurationParser ConfigParser.cpp main.cpp
-Linux: run:  g++ -g -o ../build/ConfigurationParser ConfigParser.cpp main.cpp

Usage:
-give a .ini file's (respect the rules presented on the bottom of this file) path when running the executable and the tool will import every property-value pair to its internal data structure(unordered_map)
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


.ini file rules:
-provide valid property=value pairs (properties with no values are not acceptes) 
        e.g.: server="127.0.0.1"
-each value will be interpreted as string and the user has to convert it to its type: e.g. port=80, 80 has to be converted to int after the parsing is done.
-whitespaces: --all of the whitespaces(' ', '\t', '\r', etc.) will be ignored, EXCEPT when they are between double quotes. 
                 e.g. server="   127.0.0.1"; the value of this will be exactly "   127.0.0.1"
                        port =     80        ; the value of this will be 80
-comments:  --each line which has its first character either ';' or '#' will be treated as a comment line
            --comments are not allowed to be on the same line as a property-value pair: e.g. port=80 #my port : this is not allowed
-property names are not case sensitive, so 'server' property is equal with 'SERVER'
-in case of double property definition, just the first value will be retained
-property separated with whitespace character will be concatanated: e.g.: some property="some value" will be someproperty="some value"