#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>

#include "board_game.h"

typedef std::function<void(void)> ExitCallback;

struct GameController {

    GameController(BoardGame& boardGame, ExitCallback exitCallback): boardGame(boardGame), exitCallback(exitCallback) {
        boardGame.SetWinNotification(
            [=](){
                std::cout << "You win the game!" << std::endl;
                this->exitCallback();
            });
    }
    void ServeInput();

private:
    BoardGame& boardGame;
    ExitCallback exitCallback;
};