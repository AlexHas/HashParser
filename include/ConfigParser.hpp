#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace HashParser{
    class ConfigParser{
    private:
        std::string fileName;
        std::ifstream configFile;

    public:
        ConfigParser();

        ConfigParser(std::string fileName);

        ~ConfigParser();

        void parse();

        std::string GetSettingValue(std::string key);
    };
}