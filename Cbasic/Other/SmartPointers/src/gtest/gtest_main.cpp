/*
 * Test_main.cpp
 *
 *  Created on: 2016Äê5ÔÂ9ÈÕ
 *      Author: Beven
 */

#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <iostream>

GTEST_API_ int main(int argc, char **argv)
{
	std::cout << "Running main() from gtest_main.c" << std::endl;
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

