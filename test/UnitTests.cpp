#include "../include/ConfigParser.hpp"
#include <gtest/gtest.h>

TEST(first, test) {
	std::cout << "first_test";
}

int main(int argc, char** argv){

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
    
}