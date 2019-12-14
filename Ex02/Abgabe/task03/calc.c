/*
 * calc.c
 *
 *  Created on: 30.10.2019
 *      Author: Jens
 */

#include <stdio.h>
#include <string.h>
#include "calc.h"
#define MAX_INPUT 256


/**
 * This is the main method for the calculator program and takes command line input with the fgets() method.
 * Input should be formatted as <int> <op> <int> where
 *  - <int> is an signed integer,
 *  - <op> ({'+'|'-'|'*'|'/'}) is the operation to perform. Notice that only 1 <op> must be entered, otherwise a error message will be printed.
 * Any whitespace characters before, between and after input will be ignored.
 * If only 1 '0' character is entered the program will be terminated.
 * Notice that max input is set to 256 characters to avoid invalid input.
 *
 * @return Returns 0 as program status code if main method runs without errors.
 */
int main(){

	char input[MAX_INPUT];

	while(1){
		printf("Enter <int> <op> <int>, single '0' to exit: ");
		fgets(input, MAX_INPUT, stdin);

		if(*input == '0' && strlen(input) == 2){
			puts("Goodbye");
			break;
		}

		processInput(input);
	}

	return 0;
}


