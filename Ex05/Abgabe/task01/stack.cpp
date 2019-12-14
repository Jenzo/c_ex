/*
 * stack.cpp
 *
 *  Created on: 27.11.2019
 *      Author: Jens Schröder
 */


/**
 * class defintion for Stack
 */
class Stack {

public :
	int max_capacity;
	int* stack_ptr;
	int size;

	Stack(int);
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	Stack(Stack&&);
	Stack& operator=(Stack&& other);

	~Stack();

	bool is_full();
	bool is_empty();
	int pop();
	void push(int);
	void show() const;
	int capacity() const;
	int length() const;

};



