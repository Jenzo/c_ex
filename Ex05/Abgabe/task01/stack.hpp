/*
 * stack.hpp
 *
 *  Created on: 27.11.2019
 *      Author: Jens Schröder
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "stack.cpp"
#include <iostream>
#include <cstring>

/**
 * @brief Constructor with max_capcity as int default value 10
 *
 * @param max capacity of stack. default is 10
 * @return a Stack with max_capacity and inititalized size if 0
 */
Stack::Stack(int c = 10) {
	max_capacity = c;
	size = 0;
	stack_ptr = new int[c];

	std::cout << "Ctor: I am allocating space for " << max_capacity
			<< " integers" << std::endl;
}


/**
 * @brief copy constructor
 *
 * @param Stack as right hand statement
 * @return a Stack copy
 */
Stack::Stack(const Stack& rhs){
	std::cout << "Cctor called" << std::endl;

	max_capacity = rhs.max_capacity;
	size = rhs.size;
	stack_ptr = new int[max_capacity];

	std::memcpy(stack_ptr, rhs.stack_ptr, rhs.size * sizeof(int));

}

/**
 * @brief overloaded copy operator
 *
 * @param otherStack given as reference
 * @return reference to Stack
 */
Stack& Stack::operator =(const Stack& otherStack){
	std::cout << "Cop= called" << std::endl;

	if(this != &otherStack){
		stack_ptr = otherStack.stack_ptr;
		size = otherStack.size;
		max_capacity = otherStack.max_capacity;
	}

	return *this;
}

/**
 * @brief move constructor
 *
 * @param stack reference
 * @return stack with copied data of param stack
 */
Stack::Stack(Stack&& rhs){
	std::cout << "Mctor called" << std::endl;

		stack_ptr = rhs.stack_ptr;
		std::memcpy(stack_ptr, rhs.stack_ptr, rhs.size  * sizeof(int));

		size = rhs.size;
		max_capacity = rhs.max_capacity;

		rhs.stack_ptr = NULL;
		rhs.max_capacity = 0;
		rhs.size = 0;

}

/**
 * @brief overloaded move operator
 *
 * @param stack reference
 * @return stack as reference
 */
Stack& Stack::operator=(Stack&& other){
	std::cout << "Mop= called" << std::endl;

	if(this != &other){
		stack_ptr = other.stack_ptr;
		size = other.size;
		max_capacity = other.max_capacity;

		other.stack_ptr = NULL;
		other.size = 0;
		other.max_capacity = 0;
	}

	return *this;
}

/**
 * @brief stack destructor
 */
Stack::~Stack(){
	std::cout << "Dtor: I am deallocating a stack of " << max_capacity << " integers filled with " << size << " values." << std::endl;

	delete stack_ptr;
	size = 0;
	max_capacity = 0;
}


/**
 * @brief pushes a integer to stack
 *
 * This method pushes an integer to stack, if stack is not full and increases the size of stack,
 * else "The stack is full" will be printed.
 *
 * @param i integer value to be pushed on stack
 */
void Stack::push(int i) {
	if (is_full()) {
		std::cout << "The stack is full" << std::endl;
	} else {
		*(stack_ptr + size) = i;
		size++;
	}
}

/**
 * @brief pops the last pushed integer off the stack, if stack is not empty,
 *  else "The stack is empty" will be printed.
 *  After popping size will be decremented.
 *
 * @return last pushed integer of stack as int
 */
int Stack::pop() {
	if (is_empty()) {
		std::cout << "The stack is empty" << std::endl;
		return 0;
	} else {
		int result = *(stack_ptr + size - 1);
		size--;
		return result;
	}
}

/**
 * @brief Bool method to evaluate, if stack is full, by comparing size with max_capacity.
 *
 * @return returns true if size of stack capacity is greater than max_capacity, else false
 */
bool Stack::is_full() {
	return size >= max_capacity;
}

/**
 * @brief Bool method to evaluate if stack is empty
 *
 * @return returns true if stack size equals 0, else false
 */
bool Stack::is_empty() {
	return size == 0;
}

/**
 * @brief method to print all values of calling stack with whitespaces between values
 */
void Stack::show() const {
	for (int i = 0; i < size; i++) {
		std::cout << *(stack_ptr + i) << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief gives the length of calling stack as integers
 *
 * @return return length aka size of calling stack
 */
int Stack::length() const {
	return size;
}

#endif /* STACK_HPP_ */
