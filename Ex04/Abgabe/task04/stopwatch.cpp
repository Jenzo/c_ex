/*
 * main.cpp
 *
 *  Created on: 20.11.2019
 *      Author: Jens Schröder
 */

#include <iostream>
#include <ctime>

using namespace std;


/**
 * Class definition for StopWatch
 */
class StopWatch {

	/**
	 * bool var if time measurement has started
	 */
	bool started;

	/**
	 * bool var if time measurement has stopped
	 */
	bool stopped;

	/**
	 * var to hold end time.
	 */
	clock_t end_t;

public:
	StopWatch();
	void start();
	double stop();
};

/**
 * Default constructor
 *
 * @return returns StopWatch with started and stoppped = false
 */
StopWatch::StopWatch(){
	started = false;
	stopped = false;
}
/**
 * Starts time measurement
 */
void StopWatch::start() {
	if (started) {
		std::cout << "StopWatch already running!" << std::endl;
	} else {
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
	if (!started) {
		std::cout << "StopWatch not started yet" << std::endl;
	} else {
		end_t = clock();
		stopped = true;
	}

	return difftime(clock(), end_t);
}

