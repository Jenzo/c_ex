/*
 * humanplayer.cpp
 *
 *  Created on: 18.12.2019
 *      Author: Jens Schroeder
 */

#include "humanplayer.hpp"

HumanPlayer::HumanPlayer(int turn) :
		Player(turn) {
}

void HumanPlayer::play(GameBoard &board) {

	Move move;
	while (true) {
		std::cout << "Select a row: ";
		std::cin >> move.row;
		std::cout << "Select a column: ";
		std::cin >> move.col;
		std::cout << "Player " << this->turn << ": " << move.row  << "|" << move.col << std::endl;
		move.row -= 1;
		move.col -= 1;

		if (board.isMoveValid(move.row, move.col)) {
			board.insert(turn, move.row, move.col);
			break;
		} else {
			std::cout << "Invalid field selection!" << std::endl;
		}
	}

}
