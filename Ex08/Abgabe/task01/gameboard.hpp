/*
 * gameboard.hpp
 *
 *  Created on: 18.12.2019
 *      Author: Jens
 */

#ifndef GAMEBOARD_HPP_
#define GAMEBOARD_HPP_

#include <iostream>

class GameBoard {

private:
	int size;
	int *board;
	bool isOnBoard(int, int);

public:
	GameBoard();
	GameBoard(int);

	int* getBoard();

	bool isFree(int, int);
	int& getField(int, int);
	void insert(int, int, int);

	bool isMoveValid(int, int);

	int getSize() const;
	int getWinner() const;
	bool hasAvailableMoves() const;

	bool checkWin(int);
	bool isRowFilled(int, int);
	bool isColumnFilled(int, int);
	bool isDiagonalFilled(int);
	bool isLeftToRightFilled(int);
	bool isRightToLeftFilled(int);

	void draw();

	friend std::ostream& operator<<(std::ostream&, GameBoard&);
};

#endif /* GAMEBOARD_HPP_ */
