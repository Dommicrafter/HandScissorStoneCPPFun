#include "Player.h"

Player::Player(std::string name)
{
	this->name = name;
	this->gamesWon = 0;
	this->points = 0;
}

bool Player::addPoint()
{
	this->points++;
	if (this->points == 3) 
	{
		this->points = 0;
		this->gamesWon++;
		return true;
	}
	return false;
}

int Player::getPoints()
{
	return this->points;
}

std::string Player::getName()
{
	return this->name;
}

int Player::getGamesWon()
{
	return this->gamesWon;
}

void Player::resetPoints()
{
	this->points = 0;
}
