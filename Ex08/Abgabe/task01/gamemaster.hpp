/*
 * gamemaster.hpp
 *
 *  Created on: 18.12.2019
 *      Author: Jens
 */

#ifndef GAMEMASTER_HPP_
#define GAMEMASTER_HPP_

#include "player.hpp"
#include "gameboard.hpp"

class GameMaster {
private:
	Player *player1;
	Player *player2;
	GameBoard gameboard;

	void playRound();
	void startHumanVsHuman();
	void startHumanVsComputerMinimax();
	void startHumanVsComputerRandom();
	void startComputerMinimaxVsComputerMinimax();

public:
	GameMaster();
	void start();

	GameBoard& getGameBoard() ;

};

#endif /* GAMEMASTER_HPP_ */
