/*
 * mytime.hpp
 *
 *  Created on: 04.12.2019
 *      Author: Jens Schröder
 */

#ifndef MYTIME_HPP_
#define MYTIME_HPP_

#include <iostream>

using namespace std;


/**
 * MyTime class holds time information as member variables
 * hour, minute, second.
 * Note that member variables are private and must be accessed via getter.
 *
 * Various operators are overloaded like
 * '+', '+=','=','>','<<'
 * in order to perform arithmetic operations to manipulate member variables.
 *
 */
class MyTime {

private:
	int hour;
	int minute;
	int second;
	void adjustTime();
	int asSeconds() const;

public:
	MyTime(int, int, int);

	operator int() const;
	MyTime operator=(const MyTime);

	friend MyTime operator+(int, MyTime&);

	MyTime operator+(int);

	MyTime operator+=(const MyTime&);
	MyTime& operator+=(int);

//	bool operator>(const MyTime&);

	friend ostream& operator<<(std::ostream&, MyTime);

	int getHour();
	int getMinute();
	int getSecond();
};

#endif /* MYTIME_HPP_ */

