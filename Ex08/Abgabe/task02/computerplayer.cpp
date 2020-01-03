/*
 *  gameboard.cpp
 *
 *  Created on: 18.12.2019
 *  Author: Jens Schroeder
 */

#include "computerplayer.hpp"
#include "minimax.hpp"
#include <vector>

/**
 * Computer player constructor
 *
 * @param turn players turn
 * @param mode computer player mode
 */
ComputerPlayer::ComputerPlayer(int turn, Mode mode) :
		Player(turn), mode(mode) {
}

/**
 * Implemented player play method with distinct play modes for computer player.
 *
 * @param gameboard current board to play with
 */
void ComputerPlayer::play(GameBoard &gameboard) {

	Move move;
	if (mode == RANDOM) {
		move.row = std::rand() % ((3 - 1) + 1);
		move.col = std::rand() % ((3 - 1) + 1);

		while (!gameboard.isMoveValid(move.row, move.col)) {
			move.row = std::rand() % ((3 - 1) + 1);
			move.col = std::rand() % ((3 - 1) + 1);
		}
	}

	if (mode == MINIMAX) {
		Minimax minimax;
		move = minimax.findBestMove(gameboard, turn);
	}

	gameboard.insert(turn, move.row, move.col);
	std::cout << "Player " << turn << ": " << move.row + 1 << "|" << move.col + 1 << std::endl;
}
