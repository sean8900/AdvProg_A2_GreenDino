#include <iostream>
#include <string>

#include "pages.h"

void creditsPage() {
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH/2 - 3); //3 = half of letters in CREDITS
    std::cout << "CREDITS";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    //line 4
    printString(" ", PAGEWIDTH/2 - 4);
    std::cout << "Design by";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH/2 - 4);
    std::cout << "Sean Tan";
    std::cout << std::endl;

    //line 6
    printString(" ", PAGEWIDTH/2 - 5);
    std::cout << "Aaron Soa";
    std::cout << std::endl;

    //line 7
    printString(" ", PAGEWIDTH/2 - 5);
    std::cout << "Amy Nguyen";
    std::cout << std::endl;
    std::cout << std::endl;

    //toolbar
    std::cout << "< enter B to go back to Main menu" << std::endl;
}

void mainMenuPage() {
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH/2 - 2); //3 = half of letters in AZUL
    std::cout << "AZUL";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    //line 4
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "New Game < enter 'N'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "Load Game < enter 'L'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 5
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "Credits < enter 'C'";
    std::cout << std::endl;
    std::cout << std::endl;

    //line 6
    printString(" ", PAGEWIDTH/2 - 10);
    std::cout << "Quit Game < enter 'Q'";
    std::cout << std::endl;
    std::cout << std::endl;

}

void newGamePage() {
    //line 1
    printString("=", PAGEWIDTH);
    std::cout << std::endl;

    //line 2
    printString(" ", PAGEWIDTH/2 - 4); //4 = half of letters in NEW GAME
    std::cout << "NEW GAME";
    std::cout << std::endl;

    //line 3
    printString("=", PAGEWIDTH);
    std::cout << std::endl;
    std::cout << std::endl;

    // take in player names
    std::cout << "Enter a name for player 1:" << std::endl;
    std::string playerName1;
    std::cin >> playerName1;
    std::cout << "Enter a name for player 2:" << std::endl;
    std::string playerName2;
    std::cin >> playerName2;
    std::cout << std::endl;

    // game initialised
    Game *game = new Game(playerName1, playerName2);
    bool game = true;
    std::cout << "Let’s Play!" << std::endl;
    std::cout << std::endl;
    std::cout << "=== Start Round ===" << std::endl;
    int roundCounter = 1; // odd = player 1 turn, even = player 2 turn
    while(game) {
        std::cout << "TURN FOR PLAYER: ";
        if (roundCounter % 2 == 1) {
            std::cout << playerName1 << std::endl;
        }
        else {
            std::cout << playerName2 << std::endl;
        }
        printFactories(game->getCentre(), game->getFactories());
        std::cout << std::endl;
        if (roundCounter % 2 == 1) {
            printPlayerMosaic(game->getPlayer1());
        }
        else {
            printPlayerMosaic(game->getPlayer2());
        }
        bool validMove = false;
        // loop until valid move is made
        while (!validMove) {
            std::string playerMove;
            std::cin >> playerMove;
            if (roundCounter % 2 == 1) {
                validMove = game->playerMakesMove(1, playerMove);
            }
            else {
                validMove = game->playerMakesMove(2, playerMove);
            }
        }
        std::cout << "Turn Successful." << std::endl;
        roundCounter++;
        
    }

}

void loadGamePage() {

}

