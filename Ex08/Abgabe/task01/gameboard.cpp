/*
 *  gameboard.cpp
 *
 *  Created on: 18.12.2019
 *  Author: Jens Schroeder
 */

#include "gameboard.hpp"
#include <iostream>
#include <iomanip>


/**
 * Helper method to convert players turn into char sign
 *
 * @param players turn sign
 * @return returns 'X' for player 1 and 'O' for player 2
 */
char getChar(int turn) {
	if (turn == 1) {
		return 'X';
	}
	if (turn == 2) {
		return 'O';
	}
	return ' ';
}

/**
 * GameBoard constructor with default size of 9
 *
 */
GameBoard::GameBoard() :
		size(9) {
	this->board = new int[size] { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
}

/**
 * GameBoard constructor with size parameter
 *
 * @param size for gameboard size
 */
GameBoard::GameBoard(int size) :
		size(size) {

	this->board = new int[size] { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
}

/**
 * Gameboard getter for board int pointer
 *
 * @return returns int pointer to board
 */
int* GameBoard::getBoard(){
	return this->board;
}

/**
 * Gets board int value with given row, column combination.
 *
 * @param row index
 * @param column index
 * @return board int value. could be 0 for empty, 1 for player 1 or 2 for player 2
 */
int& GameBoard::getField(int row, int col) {
	return this->board[(row * 3) + col];
}

/**
 * Draws current GameBoard fields.
 * Note that '<<' operator is overloaded
 */
void GameBoard::draw(){
	std::cout << *this << std::endl;
}

/**
 * Inserts players turn into current GameBoard at given row, column combination.
 *
 * @param turn players turn
 * @param row index
 * @param column index
 */
void GameBoard::insert(int turn, int row, int column){
	this->board[(row * 3) + column] = turn;
}

/**
 * Evaluates if move is valid for given row, column combination
 *
 * @param row index
 * @param column index
 * @return true if move is valid, else false
 */
bool GameBoard::isMoveValid(int row, int col){
	return this->isFree(row, col) && this->isOnBoard(row, col);
}

/**
 * Evaluates if field on GameBoard is free for given row, column combination
 *
 *@param row index
 *@param column index
 *@return true if field is free, else false
 */
bool GameBoard::isFree(int row, int col){
	return  this->getField(row, col) == 0;
}

/**
 * Evaluates if field is on GameBoard with given row, column combination
 *
 * @param row index
 * @param col index
 * @return true if field is o board, else false
 */
bool GameBoard::isOnBoard(int row, int col){
	int field = this->getField(row, col);

	return field >=0 && field <= 9;
}

/**
 * Getter for GameBoard size
 *
 * @return GameBoard size
 */
int GameBoard::getSize() const {
	return this->size;
}

/**
 * This method evaluates if there are more moves to play or the board is full.
 *
 * @return true if there are moves to play, else false
 */
bool GameBoard::hasAvailableMoves() const {
	for (int i = 0; i < 9; i++) {
		if (this->board[i] == 0) {
			return true;
		}
	}

	return false;
}

/**
 * Overloaded '<<' operator to print the GameBoard
 *
 * @param os output stream to write to
 * @param given GameBoard
 * @return output stream
 */
std::ostream& operator<<(std::ostream &os, GameBoard &board) {

	// 1st row
	os << "     1   " << "2   " << "3" << std::endl;
	// 2nd row
	os  <<  "   -------------" << std::endl;
	// 3rd row
	os << " 1 " << "| " << getChar(board.board[0]) << " | " << getChar(board.board[1]) << " | " << getChar(board.board[2]) << " |" << std::endl;
	// 4th row
	os <<  "   -------------" << std::endl;
	// 5th row
	os << " 2 " << "| " << getChar(board.board[3]) << " | " << getChar(board.board[4]) << " | " << getChar(board.board[5]) << " |" << std::endl;
	// 6th row
	os  << "   -------------" << std::endl;
	// 7th row
	os << " 3 " << "| " << getChar(board.board[6]) << " | " << getChar(board.board[7]) << " | " << getChar(board.board[8]) << " |" << std::endl;
	// 8th row
	os << "   -------------";

	return os;
}

/**
 * This method checks if a player has won the game by checking the rows, columns and diagonals
 * for matching players turn.
 *
 * @param turn players turn
 * @return true, if a player has won the game, else false
 */
bool GameBoard::checkWin(int turn) {
	for (int i = 0; i < 3; i++) {
		bool isRowFilled = this->isRowFilled(i, turn);
		bool isColumnFilled = this->isColumnFilled(i, turn);
		if (isRowFilled || isColumnFilled) {
			return true;
		}
	}

	if (this->isDiagonalFilled(turn)) {
		return true;
	}

	return false;
}

/**
 * This method checks if a given row is filled with players turn
 *
 * @param row index to check
 * @param turn players turn
 * @return returns true if row is filled with players turn, else false
 */
bool GameBoard::isRowFilled(int row, int turn) {

	for (int col = 0; col < 3; col++) {
		if (this->getField(row, col) != turn) {
			return false;
		}
	}
	return true;
}
/**
 * This method checks if a given column is filled with players turn
 *
 * @param column index to check
 * @param turn players turn
 * @return returns true if column is filled with players turn, else false
 */
bool GameBoard::isColumnFilled(int column, int turn) {
	for (int row = 0; row < 3; row++) {
		if (this->getField(row, column) != turn) {
			return false;
		}
	}
	return true;
}

/**
 * This method checks if the left to right diagonal is filled with players turn
 *
 * @param turn players turn
 * @return returns true if the left to right diagonal is filled with players turn, else false
 */
bool GameBoard::isLeftToRightFilled(int turn) {
	// left to right
	for (int row = 0, col = 0; row < 3; row++, col++) {
		if (this->getField(row, col) != turn) {
			return false;
		}
	}
	return true;
}

/**
 * This method checks if the right to left diagonal is filled with players turn
 *
 * @param turn players turn
 * @return returns true if the right to left diagonal is filled with players turn, else false
 */
bool GameBoard::isRightToLeftFilled(int turn) {
	// right to left
	for (int row = 0, col = 2; row < 3; row++, col--) {
		if (this->getField(row, col) != turn) {
			return false;
		}
	}

	return true;
}

/**
 * This method checks if all diagonals are filled with players turn.
 *
 * @param turn players turn
 * @return returns true if either the left to right or right to left diagonal is filled with players turn, else false
 */
bool GameBoard::isDiagonalFilled(int turn) {
	return isLeftToRightFilled(turn) || isRightToLeftFilled(turn);
}
