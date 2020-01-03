/*
 * Minimax.cpp
 *
 *  Created on: 28.12.2019
 *      Author: Jens
 */

#include "minimax.hpp"

/**
 * This Helper method swaps the player
 *
 * @param turn current players turn
 * @return returns the players opponents turn
 */
int Minimax::swapPlayer(int turn) {
	return turn == 1 ? 2 : 1;
}

/**
 * This method evaluate the winner for a current play turn.
 *
 * @param gameboard the current gameboard
 * @param turn players turn
 * @return returs 0 for a draw play, -1 if the opponent wins and 1 if the current player wins
 */
int Minimax::evaluateWinner(GameBoard &gameboard, int turn) {

	// check if current player wins
	// else check if other player wins
	// else it's a draw
	if (gameboard.checkWin(turn)) {
		return 1;
	} else if (gameboard.checkWin(swapPlayer(turn))) {
		return -1;
	} else {
		return 0;
	}
}

int Minimax::minimax(GameBoard &board, int depth, bool isMaxPlayer, int turn) {

	// evauates if current player wins
	int score = evaluateWinner(board, turn);

	// return score if there is a winner
	if (score == 1 || score == -1) {
		return score;
	}

	// return 0 if there are no moves left
	if (!board.hasAvailableMoves()) {
		return 0;
	}

	if (isMaxPlayer) {
		int bestMove = -1000;

		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {

				int &currentField = board.getField(row, col);

				// if cell is empty
				if (currentField == 0) {

					currentField = turn;
					bestMove = std::max(bestMove, minimax(board, depth + 1, !isMaxPlayer, turn));
					currentField = 0;

				}
			}
		}

		return bestMove;

	} else {

		int bestMove = 1000;

		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {

				int &currentField = board.getField(row, col);

				if (currentField == 0) {

					currentField = swapPlayer(turn);
					bestMove = std::min(bestMove, minimax(board, depth + 1, !isMaxPlayer, turn));
					currentField = 0;
				}
			}

		}
		return bestMove;
	}
}

Move Minimax::findBestMove(GameBoard &board, int turn) {

	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;
	int bestVal = -1000;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {


			// play if field is empty
			if (board.isFree(row, col)) {

				// place sign of player
				board.getField(row, col) = turn;

				// start minimax with set field
				// return possible move value
				int moveVal = minimax(board, 0, false, turn);

				// reset field
				board.getField(row, col) = 0;

				if (moveVal > bestVal) {
					bestMove.row = row;
					bestMove.col = col;
					bestVal = moveVal;
				}
			}
		}
	}

	return bestMove;

}

