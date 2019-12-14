/*
 * printsizes.c
 *
 *  Created on: 22.10.2019
 *      Author: Jens Schröder
 */

#include <stdio.h>
/**
 * This main method runs a program that prints the size (in bytes) of given types by using the 'sizeof' operator.
 *
 * @return Returns 0 if main method exits without any errors.
 */
int main(){

	printf("char %d\n", sizeof(char));
	printf("short %d\n", sizeof(short));
	printf("int %d\n", sizeof(int));
	printf("long %d\n", sizeof(long));
	printf("long long %d\n", sizeof(long long));
	printf("float %d\n", sizeof(float));
	printf("double %d\n", sizeof(double));
	printf("long double %d\n", sizeof(long double));
	printf("pointer %d\n", sizeof(int*));

	return 0;
}

