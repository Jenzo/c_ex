/*
 * main.cpp
 *
 *  Created on: 28.11.2019
 *      Author: Jens Schröder
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief global Ex class to write "---start---" and "---end---"
 *
 */
class Ex {
public:

	/**
	 * standard constructor to write "---start---" at initialization
	 */
	Ex() {
		std::cout << "---start---" << std::endl;
	}

	/**
	 * deconstructor to write "---end---" at deconstruction
	 */
	~Ex() {
		std::cout << "---end---" << std::endl;
	}
};

// init Ex to call constructor
Ex ex;

/**
 * @brief main method to write "---start---" + "Hello world!" + "---end---"
 *
 * Before entering main method, the compiler calls the standard constructor of Ex and prints "---start---".
 * In the main method "Hello world!" will be printed with "---end---".
 *
 * @return returns 0 as int status code
 */
int main(void) {
	std::cout << "Hello world!" << std::endl;
	return 0;
}

