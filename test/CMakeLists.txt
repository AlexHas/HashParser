cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../")

add_executable(
    UnitTests
    "../../../test/UnitTests.cpp"
)

target_link_libraries(
    UnitTests ConfigParserLibrary gtest gtest_main
)