#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>

#include "board_game.h"
#include "game_controller.h"

void
GameController::ServeInput() {
    switch(char c = std::getchar()) {
        case 'w': //up arrow
            std::cerr << "key up handled" << std::endl;
            std::cout << boardGame;
            break;
        case 's': //down arrow
            std::cerr << "key down handled" << std::endl;
            std::cout << boardGame;
            break;
        case 'a': //left arrow
            std::cerr << "key left handled" << std::endl;
            std::cout << boardGame;
            break;
        case 'd': //right arrow
            std::cerr << "key right handled" << std::endl;
            std::cout << boardGame;
            break;
        case 'x': //x key
            std::cerr << "key exit handled" << std::endl;
            exitCallback();
            break;
        default:
        	std::cerr << "invalid key: " << c << std::endl;
    }
}
