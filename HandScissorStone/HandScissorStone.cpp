// HandScissorStone.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include "Human.h"
#include "Game.h"



int main()
{
    std::string name;
    std::cout << "Hello World!\n";
    std::cout << "Wie heißt du eigentlich?\n";
    std::getline(std::cin, name);

    Human *player = new Human(name);
    std::cout << "Hallo " << player->getName() << "!\n\n";

    int out = Game::mainLoop(player);

    delete player;
    return out;
}

