#pragma once

#include <cstdlib>
#include <iostream>
#include <memory>
#include <functional>
#include <iomanip>
#include <ctime>
#include <vector>
#include <set>

#include "tile.h"
#include "tile_array.h"

struct BoardGame {
    BoardGame(int row, int col, int winValue): numOfCol(col), numOfRow(row), winValue(winValue) {
        Init();
    }

    void Init();
    void Start();
    void SetWinNotification(Tile::WinNotification winNotification) {
        this->winNotification = winNotification;
    }
    bool OnLeftKey();
    bool OnRightKey();
    bool OnUpKey();
    bool OnDownKey();
    void End();

private:

    int numOfCol;
    int numOfRow;
    int winValue;
    TileArray tiles;
    std::vector<BoardGameTileArray> rows;
    std::vector<BoardGameTileArray> cols;
    std::set<int> blankTiles;
    Tile::WinNotification winNotification;

    bool throwNumberToTile();
    int randomIndex(int limit) {
        std::srand(clock());
        return std::rand() % limit;
    }

    bool onAfterMove();

    friend std::ostream & operator<< (std::ostream &out, const BoardGame &boardGame);
};
