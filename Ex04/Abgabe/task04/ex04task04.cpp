/*
 * ex04task04.cpp
 *
 *  Created on: 20.11.2019
 *      Author: Jens Schröder
 */

#include "stopwatch.cpp"

/**
 * @brief This main method creates a StopWatch and calls functions
 * stop(), start(), start(), then waits for 100000000 iterations and
 * prints the calculated duration of elapsed time.
 *
 * @return int as status code but not set
 */
int main(void) {
  StopWatch sw;
  sw.stop();
  sw.start();
  sw.start();
  for (int i=0; i <100000000; i++) ;
  std::cout << "Duration: " << sw.stop() << std::endl;
}




