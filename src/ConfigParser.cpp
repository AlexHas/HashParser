#include "../include/ConfigParser.hpp"
#include <sstream>
#include <algorithm>

using namespace HashParser;

ConfigParser::ConfigParser():configFile(NULL), configurations(){}

ConfigParser::ConfigParser(std::string fileName):fileName(fileName), configFile(fileName), configurations(){}

ConfigParser::~ConfigParser(){}

bool ConfigParser::isSpace(std::string toCheck){
            bool isSpace = true;

            for(auto it = toCheck.begin(); it != toCheck.end(); ++it){
                if(!isspace(*it)){
                    isSpace = false;
                    break;
                }
            }

            return isSpace;
}

void ConfigParser::SerializeProperty(std::string lineToMap){
    /* serialize and add to configurations */
    static int lineNumber = 0;
    std::stringstream stringStream(lineToMap);
    std::string buffer, property, value;
    
    ++lineNumber;

    while(std::getline(stringStream, buffer, '=')){
        property = buffer;

        /* Property whitespaces check */
        if(ConfigParser::isSpace(property)){
            std::cout<<"Line: "<<lineNumber<<": <"<<property<<"> property can't be empty. Hint: check if there are empty lines with tabs!"<<std::endl;
            std::cout<<"Please correct the config file and restart the app!"<<std::endl;

            throw "Invalid Format Eception.";
        }else{
            if(property.find(" ") != std::string::npos){
                //std::cout<<"Property <"<<property<<"> contains empty spaces. There will be altered."<<std::endl;
                property.erase(std::remove_if(property.begin(), property.end(), ::isspace), property.end());
            }
        }

        std::getline(stringStream, value);
        if(ConfigParser::isSpace(value)){
            std::cout<<"Line: "<<lineNumber<<": Value of <"<<property<<"> property can't be empty. Please correct the config file and restart the app!"<<std::endl;
            throw "Invalid Format Eception.";
        }
        else{
            
            /* Value whitespaces check */
            if(value.find(" ") != std::string::npos){ /* value contains whitespaces */
                if(value.find("\"") != std::string::npos && value.find(" ") < value.find("\"")){ /* value contains whitespaces between "(quoete) character */
                    //std::cout<<"Value of <"<<property<<"> property has whitespaces. There will be altered."<<std::endl;
                    value.erase(std::remove_if(value.begin(), value.begin()+value.find("\""), ::isspace), value.begin()+value.find("\""));
                }
                else if(value.find("\"") == std::string::npos){ /* values contains whitespaces and no quotes */
                    //std::cout<<"Value of <"<<property<<"> property has whitespaces. There will be altered."<<std::endl;
                    value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
                }
            }
            this->configurations.insert(std::make_pair<>(property, value));
            //std::cout<<configurations[property]<<std::endl;
        }
        
    }
}

void ConfigParser::parse(){
    std::cout<<"Reading configuration file: "<<this->fileName<<std::endl;
    std::string lineFromFile;

    if(configFile.is_open()){
        while(std::getline(this->configFile, lineFromFile)){
            //std::cout<<"Line From File: "<<lineFromFile<<std::endl;
            try{
            ConfigParser::SerializeProperty(lineFromFile);
            }catch(std::string message){
                std::cout<<message<<std::endl;
                break;
            }
        }
    }
    else{
        std::cout<<"Can't open the file: "<<this->fileName<<std::endl;
    }
    
}

std::string ConfigParser::GetConfigValue(std::string key){
    return this->configurations[key];
}