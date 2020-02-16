#include "Computer.h"
#include "Human.h"
#include "Options.h"
#include <iostream>
#include "Game.h"

int Game::mainLoop(Human* player)
{
    Computer* bot1 = new Computer({ Options::Stein, Options::Schere, Options::Papier }, "Computer 1");
    Computer* bot2 = new Computer({ Options::Schere, Options::Stein, Options::Stein, Options::Papier }, "Computer 2");
    bool goOn = true;
    while (goOn)
    {
        int option = mainMenu();
        switch (option)
        {
        case 1:
            battle(player, bot1);
            break;
        case 2:
            battle(player, bot2);
            break;
        case 3:
            printStat(player);
            printStat(bot1);
            printStat(bot2);
            break;
        default:
            goOn = false;
            break;
        }
    }
    delete bot1;
    delete bot2;
    return 0;
}

void Game::printStat(Player* p)
{
    std::cout << p->getName() << " hat mittlerweile schon " << p->getGamesWon() << " Spiele gewonnen! Sehr gut!\n";
}

void Game::battle(Player* p1, Player* p2)
{
    bool nobodyWon = true;
    while (nobodyWon)
    {
        Options p1opt = p1->getOption();
        Options p2opt = p2->getOption();
        std::cout << p1->getName() << " hat die Option " << getEnumName(p1opt) << " gewählt!\n";
        std::cout << p2->getName() << " hat die Option " << getEnumName(p2opt) << " gewählt!\n\n";
        int end = compareOption(p1opt, p2opt);
        bool won1 = false;
        bool won2 = false;
        switch (end)
        {
        case 0:
            std::cout << "Niemand hat diese Runde gewonnen :(\n";
            break;
        case 1:
            std::cout << p1->getName() << " hat diese Runde gewonnen!\n";
            won1 = p1->addPoint();
            if (won1) {
                std::cout << p1->getName() << " hat dieses Spiel somit gewonnen! Herzlichen Glückwunsch \n\n\n";
                nobodyWon = false;
                break;
            }
            std::cout << "Er/Sie hat nun " << p1->getPoints() << " Punkt/e\n\n";
            break;
        case 2:
            std::cout << p2->getName() << " hat diese Runde gewonnen!\n";
            won2 = p2->addPoint();
            if (won2) {
                std::cout << p2->getName() << " hat dieses Spiel somit gewonnen! Herzlichen Glückwunsch \n\n\n";
                nobodyWon = false;
                break;
            }
            std::cout << "Er hat nun " << p2->getPoints() << " Punkt/e\n\n";
            break;
        default:
            break;
        }
    }
    p1->resetPoints();
    p2->resetPoints();
}

std::string Game::getEnumName(Options o)
{
    std::string result = "";
    switch (o)
    {
    case Options::Papier:
        result = "Papier";
        break;
    case Options::Schere:
        result = "Schere";
        break;
    case Options::Stein:
        result = "Stein";
        break;
    default:
        break;
    }

    return result;
}

int Game::compareOption(Options p1, Options p2) // 0 if nobody, 1 if P1 wins, 2 otherwise
{
    if (p1 == p2)
    {
        return 0;
    }
    if (p1 == Options::Schere && p2 == Options::Papier) {
        return 1;
    }
    if (p1 == Options::Papier && p2 == Options::Schere) {
        return 2;
    }
    if (p1 == Options::Papier && p2 == Options::Stein) {
        return 1;
    }
    if (p1 == Options::Stein && p2 == Options::Papier) {
        return 2;
    }
    if (p1 == Options::Stein && p2 == Options::Schere) {
        return 1;
    }
    if (p1 == Options::Schere && p2 == Options::Stein) {
        return 2;
    }
}

int Game::mainMenu()
{
    int option;
    std::cout << "Was möchtest du als nächstes tun?\n";
    std::cout << "(1) - Leichtes Spiel starten; (2) - schweres Spiel starten; (3) - Statistik; (4) - Spiel beenden\n";
    std::cin >> option;

    return option;
}
