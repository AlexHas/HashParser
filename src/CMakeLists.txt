cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../../../lib")

add_library(
    ConfigParserLibrary STATIC
    "../../../src/ConfigParser.cpp"
)

add_executable(
    Demo
    "../../../src/ConfigParser.cpp"
    "../../../src/main.cpp"
)