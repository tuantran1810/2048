#include <cstdlib>
#include <iostream>
#include <functional>
#include <iomanip>
#include <ctime>
#include <set>
#include "tile.h"

enum class BoardGameConfig {
    NUMROW = 4,
    NUMCOL = 4,
    WINNUM = 2048
};

struct BoardGame {
    BoardGame() {
        init();
    }

    void init();
    bool ThrowNumberToTile();

private:

    BoardGameConfig config;
    std::unique_ptr<Tile> boardMatrix[4][4];
    std::set<int> blankTiles;

    int randomIndex(int limit) {
        std::srand(std::time(nullptr));
        return std::rand() % limit;
    }
};
