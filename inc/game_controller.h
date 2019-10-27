#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <ncurses.h>

#include "board_game.h"
#include "painter.h"

typedef std::function<void(void)> ExitCallback;

struct GameController {

    GameController(BoardGame& boardGame, ExitCallback exitCallback): boardGame(boardGame), exitCallback(exitCallback) {
        initscr();
        cbreak();
        noecho();
        clearScreen();
        boardGame.SetWinNotification(
            [=](){
                printBoardGame();
                std::cout << Painter::GetInstance()->GetColor(0)
                    << "You won the game!" << std::endl << "\r";
                std::cout << Painter::GetInstance()->GetColor(0)
                    << "Press any key to exit" << std::endl << "\r";
                std::getchar();
                this->exitCallback();
            });
        boardGame.Start();
        printBoardGame();
    }

    ~GameController() {
        boardGame.End();
        endwin();
    }
    void ServeInput();

private:
    BoardGame& boardGame;
    ExitCallback exitCallback;

    void clearScreen() {
        clear();
        refresh();
    }

    void printBoardGame() {
        clearScreen();
        std::cout << boardGame << std::endl;
    }

    void handleLossenEvent() {
        std::cout << Painter::GetInstance()->GetColor(0) <<
            "You lose the game. Press any key to exit" << std::endl << "\r";
        std::getchar();
        exitCallback();
    }
};