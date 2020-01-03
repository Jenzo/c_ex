/*
 * gamemaster.cpp
 *
 *  Created on: 18.12.2019
 *      Author: Jens
 */

#include "gamemaster.hpp"
#include "humanplayer.hpp"
#include "computerplayer.hpp"

/**
 * GameMaster constructor
 * Initialize a GameBoard with 9 fields and 2 Players
 */
GameMaster::GameMaster() {
	gameboard = GameBoard(9);
	player1 = NULL;
	player2 = NULL;
}

/**
 * This method is the entry point for starting Tic Tac Toe and gives game options to play ot to leave the game
 */
void GameMaster::start() {

	int option;
	std::cout << "Choose your game mode." << std::endl;
	std::cout << "(1) Human vs. Human" << std::endl;
	std::cout << "(2) Human vs. Computer (Minimax)" << std::endl;
	std::cout << "(3) Human vs. Computer (Random)" << std::endl;
	std::cout << "(4) Computer(Minimax) vs. Computer (Minimax)" << std::endl;
	std::cout << "(5) Exit Program" << std::endl;
	std::cin >> option;

	switch (option) {
	case 1:
		startHumanVsHuman();
		break;
	case 2:
		startHumanVsComputerMinimax();
		break;
	case 3:
		startHumanVsComputerRandom();
		break;
	case 4:
		startComputerMinimaxVsComputerMinimax();
		break;
	case 5:
		std::cout << "Goodbye" << std::endl;
		exit(0);
	default:
		std::cout << "invalid input " << option
				<< ". Please enter option [1-5]." << std::endl;
	}

}

/**
 * GameMaster getter to return GameBoard
 *
 * @return returns current GameBoard of GameMaster
 */
GameBoard& GameMaster::getGameBoard(){
	return this->gameboard;
}

/**
 * This method is the actual play method for playing a round of Tic Tac Toe in choosen game mode
 */
void GameMaster::playRound() {

	this->gameboard.draw();
	std::cout << *player1 << "\n" << *player2 << "\n" << std::endl;

	int turn = 1;
	while (true) {
		if (turn % 2 == 1) {
			std::cout << "Player1's turn" << std::endl;
			player1->play(gameboard);
			turn = 1;
		} else {
			std::cout << "Player2's turn" << std::endl;
			player2->play(gameboard);
			turn = 2;
		}

		gameboard.draw();

		if (gameboard.checkWin(turn)) {
			std::cout << "Winner is: Player " << turn << std::endl;
			gameboard = GameBoard(9);
			break;
		}

		if(!gameboard.hasAvailableMoves()){
			std::cout << "A draw!" << std::endl;
			gameboard = GameBoard(9);
			break;
		}

		++turn;
	}

	this->start();
}

/**
 * Starts Human vs. Human
 * Initializes 2 HumanPlayers
 */
void GameMaster::startHumanVsHuman() {
	std::cout << "Human vs. Human" << std::endl;
	this->player1 = new HumanPlayer(1);
	this->player2 = new HumanPlayer(2);

	this->playRound();
}

/**
 * Starts Human vs. Computer in Minimax mode
 * Initializes a HumanPlayer and ComputerPlayer with Minimax mode
 */
void GameMaster::startHumanVsComputerMinimax() {
	std::cout << "Human vs. Computer(Minimax)" << std::endl;
	this->player1 = new HumanPlayer(1);
	this->player2 = new ComputerPlayer(2, MINIMAX);

	this->playRound();
}

/**
 * Starts Human vs. Computer in Random mode
 * Initializes a HumanPlayer and ComputerPlayer in Random mode
 */
void GameMaster::startHumanVsComputerRandom() {
	std::cout << "Human vs. Computer(Random)" << std::endl;
	this->player1 = new HumanPlayer(1);
	this->player2 = new ComputerPlayer(2, RANDOM);

	this->playRound();
}

/**
 * Start Computer vs Computer in Minimax mode each
 * Initializes 2 ComputerPlayer in Random mode
 */
void GameMaster::startComputerMinimaxVsComputerMinimax() {
	std::cout << "Computer(Minimax) vs. Computer(Minimax)" << std::endl;
	this->player1 = new ComputerPlayer(1, MINIMAX);
	this->player2 = new ComputerPlayer(2, MINIMAX);

	this->playRound();
}
