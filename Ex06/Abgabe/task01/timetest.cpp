/* Test program for the Time class - Exercises 4
 Missing comments are intentional :-) */

#include <iostream>
#include "mytime.hpp"


/**
 * This main method tests various expressions and statements
 * regarding to new implemented overloaded operators
 * if MyTime class.
 *
 * @return programm exit code as int, but not set
 */
int main(void) {
	MyTime t(0, 59, 121);
	std::cout << "It's " << t << std::endl; // 01:01:01
	std::cout << "Hour " << t.getHour() << " Minute " << t.getMinute()
			<< " Second " << t.getSecond() << std::endl;
	int s = t;
	std::cout << "In seconds: " << s << std::endl; // 3661 richtig
	std::cout << "Four seconds later: " << t + 4 << std::endl; // 01:01:05 richtig
	const MyTime t2(1, 59, 59);
	std::cout << "Compare: " << (t > t2 ? "bigger" : "smaller") << std::endl; // smaller richtig
	t = t+3661;
	std::cout << "Addition of int: " << t << std::endl; // 02:02:02 richtig
	t = t + t2;
	std::cout << "Addition of t2: " << t << std::endl; // 04:02:01 richtig
	t = 3784+t;
	std::cout << "Addition to int: " << t << std::endl; // 05:05:05 richtig
	t += t2;
	std::cout << "+= t2 " << t << std::endl; // 07:05:04 richtig
	t += 3784;
	std::cout << "+= int " << t << std::endl; // 08:08:08 richtig
}
