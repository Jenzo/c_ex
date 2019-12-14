/*
 * main.cpp
 *
 *  Created on: 20.11.2019
 *      Author: Jens Schröder
 */


#include <iostream>

/*
* === Add your code here, implement MAKEVAR macro
*/

/**
 * @brief This macro can be used to generate getter and setter methods by simply specify variable name and types.
 *
 * The '##', also known as token-paste operator, removes whitespace between two words, replaces 'val' with given value
 * and joins the parts together in order to generate the getter and setter methods.
 * Placeholder 't' will be replaced by given type for given variable.
 * '\' symbols define line breaks.
 *
 * @param val specifies a given variable name for getter and setter
 * @param t specifies the given variable type for getter and setter
 *
 */
#define MAKEVAR(val, t) t val;  \
	void set_ ##val (t new_val) { val = new_val; }  \
	t get_ ##val (){ return val; }


/**
 * @brief macro replacement getter and setter macro for 'weight'
 *
 * @param weight the field variable name for the getter and setter
 * @param int return and set type for 'weight'
 *
 */
MAKEVAR(weight, int)

/**
 * @brief macro replacement getter and setter macro for 'price'
 *
 * @param price the field variable name for the getter and setter
 * @param float return and set type for 'price'
 *
 */
MAKEVAR(price, float)


/**
 * @brief This main method sets weight and price with macro generated code
 *
 * @return return int as status code but is not set
 */
int main(void) {
  set_weight(100);
  set_price(1.25);
  std::cout << "Weight: " << get_weight() << ", Price: " << get_price() << std::endl;
}

