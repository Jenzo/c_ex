/*
 * computerplayer.hpp
 *
 *  Created on: 18.12.2019
 *      Author: Jens
 */

#ifndef COMPUTERPLAYER_HPP_
#define COMPUTERPLAYER_HPP_

#include "player.hpp"
#include "mode.hpp"

class ComputerPlayer: public Player {
private:
	Mode mode;

public:
	ComputerPlayer(int, Mode);
	void play(GameBoard&);

};

#endif /* COMPUTERPLAYER_HPP_ */
