#pragma once

#include <cstdlib>
#include <iostream>
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
    void End();

private:

    int numOfCol;
    int numOfRow;
    int winValue;
    TileArray tiles;
    std::vector<BoardGameTileArray> rows;
    std::vector<TileArray> cols;
    std::set<int> blankTiles;

    bool throwNumberToTile();
    int randomIndex(int limit) {
        std::srand(std::time(nullptr));
        return std::rand() % limit;
    }

    friend std::ostream & operator<< (std::ostream &out, const BoardGame &boardGame);
};
