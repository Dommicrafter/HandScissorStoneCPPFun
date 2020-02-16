#include "Human.h"
#include <iostream>

Human::Human(std::string name): Player(name)
{
}

Options Human::getOption()
{
	int option;
	std::cout << "Was möchtest du auswählen?\n";
	std::cout << "(1) - Stein; (2) - Schere; (3) - Papier  ";
	std::cin >> option;

	return Options(--option);
}
