#include <iostream>
#include "gamemaster.hpp"
#include "gameboard.hpp"


/**
 * This is the programs main method and initializes a GameMaster to play Tic Tac Toe.
 * The GameMaster starts the game directly and controls the game flow.
 *
 * @return return 0 as program exit code
 */
int main() {
	GameMaster gamemaster;
	gamemaster.start();
	return 0;

}
