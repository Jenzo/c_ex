/*
 * cubes.c
 *
 *  Created on: 22.10.2019
 *      Author: Jens Schröder
 */

#include <stdio.h>


/**
 * @brief This method returns the sum of all column values for multidimensional arrays.
 *
 * This method validate given arguments by checking if any of given dimension arguments equals less than 1.
 * If valid, pointer will be increased by 1 so it points to address of element in 2nd column of 1st row.
 * Evaluate 'size' of elements by multiplying 'rows' and 'deepth'.
 *
 * Repeats following steps, while 'size' is greater than 0:
 * 	Sums up stored value at pointers address,
 * 	decreases 'size' by 1,
 * 	calculate new pointer address of next column element by adding up column dimension;
 *
 * @param *ptr Needs to be an int pointer for first array element address.
 * @param deepth First array size.
 * @param rows Given row size.
 * @param columns Given column size.
 *
 * @return returns sum of each 2nd column values as int.
 *  If any of given dimensions equals 0 or less, then return 0.
 *  Else return sum of all 2nd column values.
 */
int sum2nd(int *ptr, int deepth, int rows, int columns){

	int sum = 0;
	int size = deepth*rows;

	if(size < 1 || columns < 1){
		return sum;
	}

	ptr++;

	while(size > 0){
		sum += *ptr;
		size--;
		ptr = ptr + columns;
	}

	return sum;
}

/**
 * This Main method initializes 2 cube arrays and prints the sum of each 2nd column to console.
 *
 * @return Returns 0 if runs without errors.
 */
int main() {

	int cube1[3][2][4] =
	{
		{
			{1,2,3,4}},
		{
			{2,3},
			{4,6,8,10}
		},
		{
			{3,4,5,6},
			{6,8,10}
		}
	};

	int cube2[2][3][3] =
	{
		{
			{9,8,7},
			{6},
			{5,4}
		},
		{
			{3,2},
			{1,2,3},
			{4}
		}
	};

	printf("%i\n", sum2nd(&cube1[0][0][0], 3, 2, 4));
	printf("%i\n", sum2nd(&cube2[0][0][0], 2, 3, 3));

	return 0;

}

