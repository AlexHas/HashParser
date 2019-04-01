#include "../include/ConfigParser.hpp"

int main(){

    HashParser::ConfigParser parser("../testToParse.ini");
    parser.parse();
    return 0;
}