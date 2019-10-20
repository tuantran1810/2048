#pragma once

#include <cstdlib>
#include <iostream>
#include <functional>
#include <iomanip>
#include <ctime>

struct Tile {

    typedef std::function<void(int, int, bool)> TileStatusCallback;
    typedef std::shared_ptr<Tile> TilePtr;

    Tile() {}

    Tile(int row, int col, int num, TileStatusCallback callback):
        row(row), col(col), num(num), statusCallback(callback) {}

    static auto CreateTile(int row, int col, TileStatusCallback callback) {
        return TilePtr(new Tile(row, col, 0, callback));
    }

    void MergeWith(Tile& other) {
        num += other.num;
        other.num = 0;
        TriggerStatusCallback();
        other.TriggerStatusCallback();
    }

    bool ContainNumber() const {
        return num > 0;
    }

    void ThrowNumber() {
        if (ContainNumber()) return;
        generateValue();
        TriggerStatusCallback();
    }

    void TriggerStatusCallback() {
        statusCallback(row, col, ContainNumber());
    }

    friend std::ostream & operator<< (std::ostream &out, const Tile &tile);

private:
    int row;
    int col;
    int num;
    TileStatusCallback statusCallback;

    void generateValue() {
        std::srand(clock());
        if (std::rand() % 2)
            num = 2;
        else
            num = 4;
    }
};
