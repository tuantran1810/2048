#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>

#include "board_game.h"
#include "game_controller.h"

int main(void) {
    std::ofstream redirectFile("log");
    std::cerr.rdbuf(redirectFile.rdbuf());

    bool running = true;
    BoardGame boardGame(4, 4, 2048);
    GameController gameController(boardGame, [&] () mutable {
        std::cerr << "exit triggered!" << std::endl;
        running = false;
    });

    std::cerr << "starting" << std::endl;
    boardGame.Start();
    std::cout << boardGame;

    while(running) {
        gameController.ServeInput();
    }

    boardGame.End();
    std::cerr << "end!!!" << std::endl;
}
