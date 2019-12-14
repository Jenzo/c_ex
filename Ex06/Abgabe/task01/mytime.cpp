/*
 * mytime.cpp
 *
 *  Created on: 04.12.2019
 *      Author: Jens
 */
#include "mytime.hpp"

#include <cstring>
#include <iostream>
#include <iomanip>


/**
 * This private method is a helper method to convert time values into right range.
 * E.g. if second value is manipulated due adding seconds using '+' operator
 * the time ranges must be adjusted into [0;59] value range.
 * Note that hour time value is not converted based on given exercise requirements.
 *
 * Mainly used in constructor calls.
 *
 */
void MyTime::adjustTime() {
	int rest_sec = this->second % 60;
	int over_to_min = this->second / 60;
	this->second = rest_sec;

	int rest_min = (this->minute + over_to_min) % 60;
	int over_to_hour = (this->minute + over_to_min) / 60;
	this->minute = rest_min;

	this->hour += over_to_hour;
}

/**
 * This private helper method converts and returns a calling MyTime object into seconds
 *
 * @return returns calling MyTime object values calculated in seconds
 */
int MyTime::asSeconds() const {
	return this->second + this->minute * 60 + this->hour * 60 * 60;
}

/**
 * Constructor with initializer list for hour, minute, second.
 * If time values are not within time range[0;59] the adjustTime()
 * method ensures a correct conversion.
 * 0 is assumed as default for time values.
 *
 * @param h new hour value as int
 * @param m new minute value as int
 * @param s new second value as int
 * @return returns a new MyTime object with given adjusted time values
 */
MyTime::MyTime(int h = 0, int m = 0, int s = 0) :
		hour(h), minute(m), second(s) {

	this->adjustTime();
}

/**
 * Overloaded '=' operator to copy values of given MyTime object values to calling
 * MyTime object. After coping adjustTime() must be called to adjust time values of
 * calling MyTime object.
 *
 * @param const MyTime object
 * @return this MyTime object with copied values of given param mytime object
 */
MyTime MyTime::operator=(const MyTime mytime) {
	this->hour = mytime.hour;
	this->minute = mytime.minute;
	this->second = mytime.second;
	this->adjustTime();

	return *this;
}

/**
 * Friend overloaded '+' operator to add an integer interpreted as seconds
 * to MyTime object. Must be a friend method to MyTime, because it must be ensured,
 * that leading integer can be added to followed MyTime object.
 *
 * @param seconds_to_add to add to given MyTime object reference
 * @param MyTime object reference
 * @return returns new MyTime object with added seconds
 */
MyTime operator+(int seconds_to_add, MyTime &mytime) {
	return MyTime(mytime.getHour(), mytime.getMinute(), mytime.getSecond() + seconds_to_add);
}

/**
 * This overloaded operator adds an integer interpreted as seconds to MyTime object
 * by calling MyTime constructor with added seconds.
 *
 * @param seconds to add to the current MyTime object
 * @return returns MyTime object with added seconds
 */
MyTime MyTime::operator+(int seconds_to_add){
	return MyTime(this->hour, this->minute, this->second + seconds_to_add);
}

/**
 * Overloaded += operator to sum-add an integer interpreted as seconds to MyTime object.
 * The seconds of MyTime object can overflow the [0;59] range so
 * adjustTime() is called to adjust time values into right ranges.
 *
 * @param seconds_to_add seconds to add to Mytime object
 * @return MyTime reference with sum-added seconds
 */
MyTime& MyTime::operator+=(int seconds_to_add) {
	this->second += seconds_to_add;
	this->adjustTime();

	return *this;
}

/**
 * Overloaded += operator to sum-add all time values of given MyTime object as paramter.
 * All values can overflow the [0;59] range so
 * adjustTime() is called to adjust time values into right ranges.
 *
 * @param MyTime reference
 * @return returns MyTime object with sum-added time values from given MyTime object reference
 */
MyTime MyTime::operator+=(const MyTime &mytime) {
	this->hour += mytime.hour;
	this->minute += mytime.minute;
	this->second += mytime.second;
	this->adjustTime();

	return *this;
}

/**
 * Custom cast to integer interpreted as seconds to assign an integer to
 * MyTime object. Calls helper method asSeconds() to return calling MyTime object
 * in seconds.
 *
 * @return returns all values of Mytime object calculated as seconds
 */
MyTime::operator int() const {
	return this->asSeconds();
}

/**
 * @brief Overloaded '<<' operator to write MyTime instance to ostream
 * into format "hh:mm:ss", e.g. MyTime object with hour=1, minute=1, second=1
 * will be printed as "01:01:01".
 *
 * This method uses the 'std::setfill()' method to fill up given values of hour, minute and second with
 * leading '0' if value is less than 9. The std:setw() method sets the parameter of the output stream to given
 * width of 2, so if value is less 9 the std:setfill() fills up to 2 character width.
 *
 * @param os current ostream
 * @param mytime MyTime object
 * @return returns given os stream with formatted MyTime values
 */
ostream& operator<<(ostream &os, MyTime mytime) {
	os << std::setfill('0') << std::setw(2) << mytime.getHour()<<":" ;
	os << std::setfill('0') << std::setw(2) << mytime.getMinute()<<":" ;
	os << std::setfill('0') << std::setw(2) << mytime.getSecond() ;
	return os;
}

/**
 * GETTER
 */

/**
 * @return returns time value 'hour' as int
 */
int MyTime::getHour() {
	return this->hour;
}

/**
 * @return returns time value 'minute' as int
 */
int MyTime::getMinute() {
	return this->minute;
}

/**
 * @return returns time 'second' as int
 */
int MyTime::getSecond() {
	return this->second;
}
