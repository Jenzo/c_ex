/*
 * humanplayer.hpp
 *
 *  Created on: 18.12.2019
 *      Author: Jens
 */

#ifndef HUMANPLAYER_HPP_
#define HUMANPLAYER_HPP_

#include "player.hpp"

/**
 * Human player class.
 * Inherits from Player
 */
class HumanPlayer: public Player {

public:
	HumanPlayer(int);
	void play(GameBoard&);
};

#endif /* HUMANPLAYER_HPP_ */
