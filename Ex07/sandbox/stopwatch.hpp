/*
 * stopwatch.hpp
 *
 *  Created on: 11.12.2019
 *      Author: Jens Schröder
 */

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <ctime>

/**
 * Class definition for StopWatch
 */
class StopWatch {

	/**
	 * bool var if time measurement has started
	 */
	bool started;

	/**
	 * var to hold end time.
	 */
	clock_t startTime;

public:
	StopWatch();
	void start();
	double stop();
};

#endif /* STOPWATCH_HPP */

