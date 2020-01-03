/*
 * player.cpp
 *
 *  Created on: 18.12.2019
 *  Author: Jens Schroeder
 */

#include <iostream>
#include "player.hpp"

/**
 * Player constructor
 *
 * @param turn should be 1 for player1 or 2 for player 2
 */
Player::Player(int turn) :
		turn(turn) {
}

/**
 * Player deconstructor
 */
Player::~Player() {

}

/**
 * This method is the main play method for a player and prints the players turn
 *
 * @param gameboard to play with
 */
void Player::play(GameBoard &gameboard){
	std::cout << "Player " << this->turn << "'s turn" << std::endl;

}

/**
 * Overloaded '<<' operator to print the given player and its turn sign
 *
 * @param os output stream to write to
 * @param calling player
 */
std::ostream& operator<<(std::ostream &os, Player &player) {

	os << "Player " << player.turn << ": " << (player.turn == 1 ? 'X' : 'O');
	return os;
}

/**
 * Players turn getter
 *
 * @return calling players turn
 */
int Player::getTurn() {
	return this->turn;
}
