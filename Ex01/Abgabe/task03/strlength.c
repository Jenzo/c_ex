/*
 * strlength.c
 *
 *  Created on: 25.10.2019
 *      Author: Jens Schröder
 */

#include <stdio.h>

/**
 * @param ptr Pointer that points to address of first element of array.
 * @return Returns calculated length of
 */
int lengthByIndex(char *ptr) {

	int length = 0;
	while(ptr[length] != '\0'){
		length++;
	}

	return length;

}
/**
 * This method return the length
 *
 * @param start First element pointer to start address of char array.
 * @return Returns calculated difference between end and start.
 */
int lengthByPointerArithmetic(char *start) {

	char *end = start;
	while(*end != '\0'){
		end++;
	}

	return end - start;
}

/**
 * Main method accepts only 1 single string as command line parameter.
 * If number of given parameters is greater or less than 1, print "wrong input"
 * to command line. Else print calculated size of given command line argument to command line.
 *
 * If number of command line arguments is valid, then calculate length of given string by 2 different methods.
 *
 * @param argc Number of command line arguments.
 * @param *argv[] Array of character pointers listing all the arguments. First 
 *
 * @return Returns 0 if programm runs without error, even if more than 1 argument is given by command line.
 */
int main(int argc, char* argv[]) {

	if(argc > 2 || argc == 1) {
		printf("wrong input\n");
		return 0;
	}


	char *ptr_input = argv[1];
	printf("%i\n", lengthByIndex(ptr_input));
	printf("%i\n", lengthByPointerArithmetic(ptr_input));

	return 0;

}


