#include "../include/ConfigParser.hpp"

int main(int argc, char** argv){

    HashParser::ConfigParser parser("../testToParse.ini");
    parser.parse();
    std::cout<<parser;
    std::string value = parser.GetConfigValue("server");
    std::cout<<value;
    return 0;
}