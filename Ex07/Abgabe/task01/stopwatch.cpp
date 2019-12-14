/*
 * stopwatch.hpp
 *
 *  Created on: 29.11.2019
 *      Author: Jens
 */

#include <iostream>
#include "stopwatch.hpp"

using namespace std;

/**
 * Default constructor
 *
 * @return returns StopWatch with started and stopped = false
 */
StopWatch::StopWatch() :
		started(false) {
}

/**
 * Starts time measurement
 */
void StopWatch::start() {
	if (started) {
		cout << "StopWatch already running!" << endl;
	} else {
		startTime = clock();
		started = true;
	}
}

/**
 * Stops time measurement
 *
 * @return returns elapsed time since start() in seconds as double value
 *
 */
double StopWatch::stop() {
	clock_t endTime = clock();
	if (!started) {
		std::cout << "StopWatch not started yet" << std::endl;
		return 0;
	} else {
		started = false;
		return ((double) endTime - startTime);
	}

}

