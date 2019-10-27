#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "board_game.h"
#include "game_controller.h"

int main(int argc, char* argv[]) {
    std::ofstream redirectFile("log");
    std::cerr.rdbuf(redirectFile.rdbuf());

    int numOfRows = 4;
    int numOfCols = 4;
    int winNum = 2048;

    if (argc == 4) {
        numOfRows = std::stoi(argv[1]);
        numOfCols = std::stoi(argv[2]);
        winNum = std::stoi(argv[3]);
    }

    bool running = true;
    BoardGame boardGame(numOfRows, numOfCols, winNum);
    GameController gameController(boardGame, [&] () mutable {
        std::cerr << "exit triggered!" << std::endl;
        running = false;
    });

    std::cerr << "starting" << std::endl;

    while(running) {
        gameController.ServeInput();
    }

    std::cerr << "end!!!" << std::endl;
    return 0;
}
