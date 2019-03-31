#include "../include/ConfigParser.hpp"
using namespace HashParser;

ConfigParser::ConfigParser():configFile(NULL){}

ConfigParser::ConfigParser(std::string fileName):fileName(fileName), configFile(fileName){}

ConfigParser::~ConfigParser(){}

void ConfigParser::parse(){
    std::cout<<"File to parse: "<<this->fileName<<std::endl;
}

std::string ConfigParser::GetSettingValue(std::string key){
    return "Get the value for " + key;
}