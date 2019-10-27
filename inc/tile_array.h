#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include "tile.h"

typedef std::vector<Tile::TilePtr> TileArray;

struct BoardGameTileArray : public TileArray {
    BoardGameTileArray() {
        this->clear();
        modified = false;
    }

    void MergeLeft();
    void MergeRight();
    void MergeUp();
    void MergeDown();
    bool ModifiedGetReset() {
        bool tmp = modified;
        modified = false;
        return tmp;
    }

    bool Mergeable();

    friend std::ostream & operator<< (std::ostream &out, const BoardGameTileArray &tile);

private:
    int __mergeLeft(int baseIndex);
    int __mergeRight(int baseIndex);
    int __findNextLeftAvailable(int baseIndex);
    int __findNextRightAvailable(int baseIndex);
    int __mergeable(int baseIndex, bool& result);

    bool modified;
};
