#include "board_game.h"

void
BoardGame::init() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardMatrix[i][j] = Tile::CreateTile(i, j, [=] (int row, int col, bool containNumber) {
                int index = row*4 + col;
                if (containNumber) {
                    std::set<int>::iterator it = blankTiles.find(index);
                    if (it != blankTiles.end()) blankTiles.erase(it);
                    return;
                }
                blankTiles.insert(index);
            });
        }
    }
}

bool
BoardGame::ThrowNumberToTile() {
    if (blankTiles.empty()) return false;
    int index = randomIndex(blankTiles.size());
    auto it = blankTiles.begin()
    for (int i = 0; i <= index; i++, it++) {}
    int tileRow = *it/4;
    int tileCol = *it%4;
    boardMatrix[tileRow][tileCol].ThrowNumber();
    return true;
}
