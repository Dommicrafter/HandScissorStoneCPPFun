#pragma once

#ifndef __Game_H_INCLUDED__
#define __Game_H_INCLUDED__

#include "Player.h"
#include "Human.h"

namespace Game {
	int mainLoop(Human* player);
	void printStat(Player* p);
	void battle(Player* p1, Player* p2);
	std::string getEnumName(Options o);
	int compareOption(Options p1, Options p2);
	int mainMenu();
}

#endif
