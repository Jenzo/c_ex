/*
 * scope1.c
 *
 *  Created on: 30.10.2019
 *      Author: Jens
 */

#include <stdio.h>

int globalvar = 1;

int main() {
	modtest();
	printf("globalvar = %d\n", globalvar);
}


