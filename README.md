# HashParser
C++ Configuration files Parser

Prerequisite:
-gcc compiler
-cmake builder
-python 3
-linux-based OS (tested on Ubuntu) or Windows


Build instructions:
-run builder.py
-project executable will be built in ./build folder as an example
    and the library will be in ./lib

Usage:
-build the project
-include the header (include/ConfigPArser.hpp)
-link the library(from lib folder)
-instantiate a ConfigParser(namespace HashParser) with a .ini file path as an argument
-call the parse() method
-use GetConfigValue(std::string key) function with the desired property as parameter which will return the value of it as a string

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