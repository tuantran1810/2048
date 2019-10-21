#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <ncurses.h>

#include "board_game.h"
#include "game_controller.h"

void
GameController::ServeInput() {
    // clear();

    switch(char c = std::getchar()) {
        case 'w':
            std::cerr << "key up handled" << std::endl;
            if(!boardGame.OnUpKey()) exitCallback();
            std::cout << boardGame << "\r";
            break;
        case 's':
            std::cerr << "key down handled" << std::endl;
            if(!boardGame.OnDownKey()) exitCallback();
            std::cout << boardGame << "\r";
            break;
        case 'a':
            std::cerr << "key left handled" << std::endl;
            if(!boardGame.OnLeftKey()) exitCallback();
            std::cout << boardGame << "\r";
            break;
        case 'd':
            std::cerr << "key right handled" << std::endl;
            if(!boardGame.OnRightKey()) exitCallback();
            std::cout << boardGame << "\r";
            break;
        case 'x':
            std::cerr << "key exit handled" << std::endl;
            exitCallback();
            break;
        default:
            std::cerr << "invalid key: " << c << std::endl;
    }
    refresh();
}
