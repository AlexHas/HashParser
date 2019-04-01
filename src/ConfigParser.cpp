#include "../include/ConfigParser.hpp"
#include <sstream>

using namespace HashParser;

ConfigParser::ConfigParser():configFile(NULL), configurations(){}

ConfigParser::ConfigParser(std::string fileName):fileName(fileName), configFile(fileName), configurations(){}

ConfigParser::~ConfigParser(){}

//serialize each line of the file to a key(property)-value pair of the configuration map member
void ConfigParser::SerializeProperty(std::string lineToMap, std::unordered_map<std::string, std::string> configurations){
    //serialize and add to configurations
}

//serialize all the file to property-value pairs
void ConfigParser::parse(){
    std::cout<<"Reading configuration file: "<<this->fileName<<std::endl;
    std::string lineFromFile;

    if(configFile.is_open()){
        while(std::getline(this->configFile, lineFromFile)){
            std::cout<<lineFromFile<<std::endl;
            ConfigParser::SerializeProperty(lineFromFile, this->configurations);
        }
    }
    else{
        std::cout<<"Can't open the file: "<<this->fileName<<std::endl;
    }
    
}

//return the value to a certain property
std::string ConfigParser::GetConfigValue(std::string key){
    return "Get the value for " + key;
}