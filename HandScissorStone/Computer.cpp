#include "Computer.h"

Computer::Computer(std::vector<Options> order, std::string name) : Player(name)
{
	this->currentPoint = 0;
	this->order = order;
	this->name = name;
}

Options Computer::getOption()
{
	Options current = this->order[this->currentPoint];
	this->currentPoint++;
	if (this->currentPoint == this->order.size()) 
	{
		this->currentPoint = 0;
	}
	return current;
}
