#pragma once
#include <string>

#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include "Options.h"

class Player
{
public:
	Player(std::string name);
	bool addPoint(); //true if won
	int getPoints();
	std::string getName();
	int getGamesWon();
	void resetPoints();
	virtual Options getOption()=0;
	~Player() {};
protected:
	std::string name;
	int points;
	int gamesWon;
};

#endif