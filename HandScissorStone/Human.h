#pragma once

#ifndef __Human_H_INCLUDED__
#define __Human_H_INCLUDED__

#include "Player.h"

class Human : public Player
{
public:
	Human(std::string name);
	virtual Options getOption();
};

#endif
