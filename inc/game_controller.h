#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <ncurses.h>

#include "board_game.h"

typedef std::function<void(void)> ExitCallback;

struct GameController {

    GameController(BoardGame& boardGame, ExitCallback exitCallback): boardGame(boardGame), exitCallback(exitCallback) {
        initscr();
        cbreak();
        noecho();
        clear();
        boardGame.SetWinNotification(
            [=](){
                std::cout << "You win the game!" << std::endl << "\r";
                this->exitCallback();
            });
    }

    ~GameController() {
        endwin();
    }
    void ServeInput();

private:
    BoardGame& boardGame;
    ExitCallback exitCallback;
};