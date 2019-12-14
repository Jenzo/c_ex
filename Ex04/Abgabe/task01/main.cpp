/*
 * main.cpp
 *
 *  Created on: 20.11.2019
 *      Author: Jens Schröder
 */

#include <iostream>
using namespace std;

/*
========  ADD YOUR CODE HERE ================
* Implement macro MAXM()
* Implement both maxf() functions
*/

/**
 * @brief Can be used to return the maximum of two numeric values.
 *
 * Note: If a and b are equal b will be returned!
 *
 * @param a is a numeric value
 * @param a is a numeric value
 */
#define MAXM(a, b)((a > b ? a : b))


/**
 * @brief This method compares 2 int values and returns the maximum
 *
 * Note: If a and b are equal b will be returned!
 *
 * @param a is an int value
 * @param b is an int value
 * @return returns the maximum of given parameters as int
 */
int maxf(int a, int b){
	std::cout << "In maxf(int)" << " ";
	return  a > b ? a : b;
}


/**
 * @brief This method compares 2 double values and returns the maximum
 *
 * Note: If a and b are equal b will be returned!
 *
 * @param a is an double value
 * @param b is an double value
 * @return returns the maximum of given parameters as double
 */
double maxf(double a, double b) {
	std::cout << "In maxf(double)" << " ";
	return a > b ? a : b;
}

/**
 * @brief This main method is a test template to test maxf-functions ans MAXM macro
 *
 * @return int as status code but is not set
 */
int main(void) {
  int a = 10, b = 20;
  std::cout << "MAXM1 = " << MAXM(a,b)      << std::endl;
  std::cout << "MAXM2 = " << MAXM(a,b+0.2)  << std::endl;
  std::cout << "MAXM3 = " << MAXM(a,b++)    << std::endl;

  std::cout << "maxf1 = " << maxf(a,b)      << std::endl;
  // what's the problem with the following line?
  //std::cout << "maxf = " << maxf(a,b+0.2)   << std::endl;
  std::cout << "maxf2 = " << maxf(a+0.1,b+0.2)  << std::endl;
  std::cout << "maxf3 = " << maxf(a,b++)        << std::endl;
  std::cout << "a = " << a << ", b = " << b     << std::endl;
}


