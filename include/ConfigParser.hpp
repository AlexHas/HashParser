#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

namespace HashParser{
    class ConfigParser{
    private:
        std::string fileName;
        std::ifstream configFile;
        std::unordered_map<std::string, std::string> configurations;

    public:
        ConfigParser();

        ConfigParser(std::string fileName);

        ~ConfigParser();

        void parse();

        std::string GetConfigValue(std::string key);

        static void SerializeProperty(std::string, std::unordered_map<std::string, std::string>);

        //print all the property-value pairs
        friend std::ostream& operator<<(std::ostream& out, HashParser::ConfigParser parser){
            for(auto it = parser.configurations.begin(); it != parser.configurations.end(); ++it){
                out<<it->first<<std::endl;
            }

            return out;
        }
    };
}