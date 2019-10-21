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

    if (argc != 4) {
        std::cerr << "wrong configuration" << std::endl;
        return 0;
    }

    int numOfRows = std::stoi(argv[1]);
    int numOfCols = std::stoi(argv[2]);
    int winNum = std::stoi(argv[3]);

    bool running = true;
    BoardGame boardGame(numOfRows, numOfCols, winNum);
    GameController gameController(boardGame, [&] () mutable {
        std::cerr << "exit triggered!" << std::endl;
        running = false;
    });

    std::cerr << "starting" << std::endl;
    boardGame.Start();
    std::cout << boardGame << "\r";

    while(running) {
        gameController.ServeInput();
    }

    boardGame.End();
    std::cerr << "end!!!" << std::endl;
    return 0;
}
