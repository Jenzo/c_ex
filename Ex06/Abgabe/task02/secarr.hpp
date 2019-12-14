/*
 * secarr.hpp
 *
 *  Created on: 04.12.2019
 *      Author: Jens
 */

#ifndef SECARR_HPP_
#define SECARR_HPP_


/**
 * This SecArr class ensures secure access to an array of ints.
 */
class SecArr {

private:
	int *first;
	int *last;
	int *current;

public:
	SecArr(int*, int*);

	int& operator*();
	int& operator[](int);

	SecArr& operator--(); // pre-increment
	SecArr& operator++(); // pre-increment

	SecArr operator--(int); // post-increment
	SecArr operator++(int); // post-increment

	int* getCurrent() const {
		return current;
	}

	int* getFirst() const {
		return first;
	}

	int* getLast() const {
		return last;
	}
};

#endif /* SECARR_HPP_ */

