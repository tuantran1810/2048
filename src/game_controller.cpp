#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <ncurses.h>

#include "board_game.h"
#include "game_controller.h"

void
GameController::ServeInput() {
    switch(char c = std::getchar()) {
        case 'w':
            std::cerr << "key up handled" << std::endl;
            if(!boardGame.OnUpKey()) handleLossenEvent();
            printBoardGame();
            break;
        case 's':
            std::cerr << "key down handled" << std::endl;
            if(!boardGame.OnDownKey()) handleLossenEvent();
            printBoardGame();
            break;
        case 'a':
            std::cerr << "key left handled" << std::endl;
            if(!boardGame.OnLeftKey()) handleLossenEvent();
            printBoardGame();
            break;
        case 'd':
            std::cerr << "key right handled" << std::endl;
            if(!boardGame.OnRightKey()) handleLossenEvent();
            printBoardGame();
            break;
        case 'x':
            std::cerr << "key exit handled" << std::endl;
            std::cout << Painter::GetInstance()->GetColor(0) <<
                "You want to exit the game? (y/n)" << std::endl << "\r";
            if (std::getchar() == 'y')
                exitCallback();
            else
                printBoardGame();
            break;
        default:
            std::cerr << "invalid key: " << c << std::endl;
    }
}
