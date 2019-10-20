#include <cstdlib>
#include <iostream>
#include <sstream>

#include "tile.h"
#include "tile_array.h"

void
BoardGameTileArray::MergeLeft() {
    auto base = (*this)[0];
    if (base != nullptr)
        if (base->ContainNumber()) {

        } else {

        }
}

void
BoardGameTileArray::MergeRight() {

}

void
BoardGameTileArray::MergeUp() {
    MergeLeft();
}

void
BoardGameTileArray::MergeDown() {
    MergeRight();
}

int
BoardGameTileArray::__mergeLeft(int baseIndex) {
    if (not (baseIndex > 0 and baseIndex < this->size())) return nullptr;
    auto base = (*this)[baseIndex];
    if (base == nullptr) return nullptr;
    if (base->ContainNumber()) {

    } else {

    }
}

int
BoardGameTileArray::__mergeRight(int baseIndex) {

}

std::ostream& operator<< (std::ostream& out, const BoardGameTileArray& array) {
    std::stringstream ss;
    for (int i = 0; i < array.size(); i++)
        ss << (*array[i]);
    ss << std::endl;

    out << ss.str();
    return out;
}
