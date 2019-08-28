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

        /* Check if a string is full with spaces, tabs, or other redundant character */
        static bool isSpace(const std::string&);


        /* Check if the new line is a comment */
        static bool isComment(const std::string&);
        
        /* Serialize a configFile line to a property-value pair */
        void SerializeProperty(const std::string&);

    public:
        ConfigParser();

        ConfigParser(const std::string& fileName);

        ~ConfigParser();

		ConfigParser(ConfigParser&&) = default;

		ConfigParser& operator=(const ConfigParser&) = delete;

        /* Read and maintain all the configurations from the input file */
        void parse();

        /* Return a value of a property */
        const std::string& GetConfigValue(std::string key);

        /* Print all the property-value pairs */
        friend std::ostream& operator<<(std::ostream& out, const HashParser::ConfigParser& parser){
            for(auto it = parser.configurations.begin(); it != parser.configurations.end(); ++it){
                out<<"Property: "<<it->first<<" = "<<it->second<<std::endl;
            }

            return out;
        }

        
    };
}