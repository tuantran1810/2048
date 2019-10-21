#include <cstdlib>
#include <iostream>
#include <sstream>

#include "tile.h"
#include "tile_array.h"

void
BoardGameTileArray::MergeLeft() {
    int next = 0;
    do {
        next = __mergeLeft(next);
    } while(next > 0);
}

void
BoardGameTileArray::MergeRight() {
    int next = this->size() - 1;
    do {
        next = __mergeRight(next);
    } while(next > 0);
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
    if (not (baseIndex >= 0 and baseIndex < static_cast<int>(this->size()))) return -1;
    auto base = (*this)[baseIndex];
    if (base == nullptr) return -1;

    auto nextAvailable = __findNextRightAvailable(baseIndex);
    if (nextAvailable != -1 && (*this)[nextAvailable] != nullptr) {
        if (base->ContainNumber())
            base->MergeWith(*(*this)[nextAvailable]);
        else
            base->Swap(*(*this)[nextAvailable]);
        return baseIndex + 1;
    }
    return -1;
}

int
BoardGameTileArray::__mergeRight(int baseIndex) {
    if (not (baseIndex >= 0 and baseIndex < static_cast<int>(this->size()))) return -1;
    auto base = (*this)[baseIndex];
    if (base == nullptr) return -1;

    auto nextAvailable = __findNextLeftAvailable(baseIndex);
    if (nextAvailable != -1 && (*this)[nextAvailable] != nullptr) {
        if (base->ContainNumber())
            base->MergeWith(*(*this)[nextAvailable]);
        else
            base->Swap(*(*this)[nextAvailable]);
        return baseIndex - 1;
    }
    return -1;
}

int
BoardGameTileArray::__findNextRightAvailable(int baseIndex) {
    if (not (baseIndex >= 0 and baseIndex < static_cast<int>(this->size()))) return -1;
    for (int i = baseIndex + 1; i < static_cast<int>(this->size()); i++) {
        auto cellPtr = (*this)[i];
        if (cellPtr == nullptr) continue;
        if (cellPtr->ContainNumber()) return i;
    }
    return -1;
}

int
BoardGameTileArray::__findNextLeftAvailable(int baseIndex) {
    if (not (baseIndex >= 0 and baseIndex < static_cast<int>(this->size()))) return -1;
    for (int i = baseIndex - 1; i >= 0; i--) {
        auto cellPtr = (*this)[i];
        if (cellPtr == nullptr) continue;
        if (cellPtr->ContainNumber()) return i;
    }
    return -1;
}

std::ostream& operator<< (std::ostream& out, const BoardGameTileArray& array) {
    std::stringstream ss;
    for (int i = 0; i < static_cast<int>(array.size()); i++)
        ss << (*array[i]);
    ss << std::endl << "\r";

    out << ss.str();
    return out;
}
