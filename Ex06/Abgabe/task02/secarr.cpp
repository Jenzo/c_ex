/*
 * secarr.cpp
 *
 *  Created on: 04.12.2019
 *      Author: Jens
 */

#include <iostream>
#include "secarr.hpp"

/**
 * Constructor with initializer list with 'first' and 'last'
 * as pointers to the first element in SecArr and to the last element
 * in SecArr.
 * If last points to element before first element, the last pointer will point
 * to fist element.
 * The pointer for the current element in SecArr will be set to first element by default.
 *
 */
SecArr::SecArr(int *first, int *last) :
		first(first), last(last) {

	if (last <= first) {
		std::cout << "warning" << std::endl;
		this->last = this->first;
	}

	this->current = first;
}

/**
 * Overloaded '*' operator to return current element of SecArr.
 *
 * @return current element as int reference
 */
int& SecArr::operator*() {
	return *this->current;
}


/**
 * Overloaded '[]' operator to get element of SecArr relative of current element.
 * If given relative position would be out of bounds of SecArr,
 * then 'Invalid index' is printed and the last or first element will be returned.
 * If given parameter i is positive, the last element will be returned.
 * If given parameter i is negative, the first element will be returned.
 *
 * @param i desired position relative to current element
 * @return returns desired element relative to position of current element, or first or last element. see method description.
 */
int& SecArr::operator[](int i) {

	if ((*(this->current + i) > *this->last) // out of upperbound
	|| (*(this->current + i) < *this->first)) { // out of lower bound
		std::cout << "Invalid index";
		return i > 0 ? *this->last : *this->first;
	}
	return *(this->current + i); // if is valid in bounds then return element +/- relative to current element
}

/**
 * Overloaded pre-decrement operator.
 * If current element points at first element of SecArr,
 * then only prints 'Invalid index' and ignore operation.
 * If pre-decrement is possible, then pre-decrement current position pointer.
 *
 * @return reference to calling SecArr object
 */
SecArr& SecArr::operator--() { // pre-decrement

	if (this->current == this->first) {
		std::cout << "Invalid index";
	} else {
		--this->current;
	}
	return *this;
}

/**
 * Overloaded post-decrement operator.
 * If current element points at first element of SecArr,
 * then only prints 'Invalid index' and ignore operation.
 * If post-decrement is possible, then post-decrement current position pointer.
 *
 * Notice, that only a copy with values of calling SecArr with old current value is returned.
 * The post-decrement will be applied for calling SecArr object and not return copy.
 *
 * @param pseudo int to tell compiler, that this is an post-decrement/increment operator
 * @return a copy of calling element with old current value
 */
SecArr SecArr::operator--(int) { // post-decrement

	if (this->current == this->first) {
		std::cout << "Invalid index";
		return *this;
	} else {
		SecArr tmp = *this;
		this->current--;
		return tmp;
	}
}

/**
 * Overloaded pre-increment operator.
 * If current element points at last element of SecArr,
 * then only prints 'Invalid index' and ignore operation.
 * If pre-increment is possible, then pre-increment current position pointer.
 *
 * @return reference to calling SecArr object
 */
SecArr& SecArr::operator++() { // pre-increment

	if (this->current == this->last) {
		std::cout << "Invalid index";
	} else {
		++this->current;

	}
	return *this;
}

/**
 * Overloaded post-increment operator.
 * If current element points at last element of SecArr,
 * then only prints 'Invalid index' and ignore operation.
 * If post-increment is possible, then post-increment current position pointer.
 *
 * Notice, that only a copy with values of calling SecArr with old current value is returned.
 * The post-increment will be applied for calling SecArr object and not return copy.
 *
 * @param pseudo int to tell compiler, that this is an post-decrement/increment operator
 * @return a copy of calling element with old current value
 */
SecArr SecArr::operator++(int) { // post-increment

	if (this->current == this->last) {
		std::cout << "Invalid index";
		return *this;
	} else {
		SecArr tmp = *this;
		this->current++;
		return tmp;
	}
}



