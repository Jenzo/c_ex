/*
 * minimax.hpp
 *
 *  Created on: 28.12.2019
 *      Author: Jens
 */

#ifndef MINIMAX_HPP_
#define MINIMAX_HPP_

#include "gameboard.hpp"
#include "move.hpp"

class Minimax {
	int swapPlayer(int);
	int evaluateWinner(GameBoard&, int);
	int minimax(GameBoard&, int , bool, int);

public:
	Move findBestMove(GameBoard&, int);
};

#endif /* MINIMAX_HPP_ */
