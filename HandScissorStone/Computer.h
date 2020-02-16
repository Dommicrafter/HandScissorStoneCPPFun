#pragma once

#ifndef __COMPUTER_H_INCLUDED__
#define __COMPUTER_H_INCLUDED__

#include "Options.h"
#include "Player.h"
#include <list>
#include <string>
#include <vector>

class Computer : public Player
{
public:
	Computer(std::vector<Options> order, std::string name);
	virtual Options getOption();
private:
	std::vector<Options> order;
	int currentPoint;
};

#endif
