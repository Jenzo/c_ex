/*
 * calc.h
 *
 *  Created on: 31.10.2019
 *      Author: Jens
 */

#ifndef CALC_H_
#define CALC_H_


void processInput(char* ptr_input);
void print_invalidInput();
void print_result(int, char, int, int);

/**
 * @brief This method gets the input entered in command line, checks the input for valid formatting
 * and prints the result of calculation.
 *
 * This method processes and calculates the entered input character array pointer from command line.
 * The used sscanf() gets the entered input pointer and checks the given valid format.
 * The entered input must consists of <int> <op> <int> where
 * <int> must be an integer and <op> must be {'+'|'-'|'*'|'/'}.
 * sscanf() returns number of fields that were successfully converted and assigned.
 * If return of sscanf() equals 3, we know that input is valid and operation will be
 * performed and printed as input entered. If input is invalid a error message 'invalid input'
 * will be printed.
 *
 * Notice that invalid input could occur for following reasons:
 * - <op> is not a member of {'+'|'-'|'*'|'/'}.
 * - More than 1 <op> was entered.
 * - No input was entered.
 * - More than 1 '0' was entered. (To exit program)
 * - <int> is not an integer but any other character.
 *
 * @param *ptr_input - Pointer to input character array
 */
void processInput(char* ptr_input){
	int in_1, in_2;
	char op;
	int result = 0;
	char rest;

	int check_result = sscanf(ptr_input, " %d %c %d %c", &in_1, &op, &in_2, &rest);

	if(check_result == 4){
		print_invalidInput();
		return;
	}

	if(check_result == 3){
		switch(op){
		case '+':
			result = in_1 + in_2;
			break;
		case '-':
			result = in_1 - in_2;
			break;
		case '*':
			result = in_1 * in_2;
			break;
		case '/':
			if(in_2 == 0){
				print_invalidInput();
				return;
			}
			result = in_1 / in_2;
			break;
		default:
			print_invalidInput();
			return;
		}

		print_result(in_1, op, in_2, result);

	} else {
		print_invalidInput();
	}

	in_1 = in_2 = 0;
	op = ' ';
}

/**
 * This method prints a formatted string to command line.
 *
 * @param in_1 - First operand of input
 * @param op - Operation to perform
 * @param in_2 - Second operand of input
 * @param result - result of input operation
 */
void print_result(int in_1, char op, int in_2, int result){
	printf("%d %c %d = %d\n", in_1, op, in_2, result);
}

/**
 * This method prints 'invalid input' to command line.
 */
void print_invalidInput(){
	printf("%s", "invalid input\n");
}

#endif /* CALC_H_ */
