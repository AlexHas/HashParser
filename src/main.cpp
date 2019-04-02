#include "../include/ConfigParser.hpp"

int main(int argc, char** argv){

    std::string fileName;
    if(argc>1){
        fileName = argv[1];
    }
    else{
        std::cout<<"Please give the configuration file's path: "<<std::endl;
        std::cin>>fileName;
    }

    HashParser::ConfigParser parser(fileName);
    parser.parse();
    std::cout<<parser;
    std::string value = parser.GetConfigValue("server");
    std::cout<<value;
    
    return 0;
}