/*
 * Player.hpp
 *
 *  Created on: 18.12.2019
 *      Author: Jens Schroeder
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include "gameboard.hpp"
#include "move.hpp"


/**
 * Player classs
 */
class Player {
protected:
	int turn;
	Player(int);
	virtual ~Player();

public:
	virtual void play(GameBoard&) = 0;
	friend std::ostream& operator<<(std::ostream&, Player&);
	int getTurn();

};

#endif /* PLAYER_HPP_ */
