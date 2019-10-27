#pragma once

#include <cstdlib>
#include <iostream>
#include <functional>
#include <iomanip>
#include <memory>
#include <ctime>
#include "painter.h"

struct Tile {

    typedef std::function<void(int, int, bool)> TileStatusCallback;
    typedef std::function<void(void)> WinNotification;
    typedef std::shared_ptr<Tile> TilePtr;

    Tile() {}

    Tile(int row, int col, int num, int winValue, TileStatusCallback callback, WinNotification winCallback):
        row(row), col(col), num(num), winValue(winValue), statusCallback(callback), winCallback(winCallback) {}

    static auto CreateTile(int row, int col, int winValue, TileStatusCallback callback, WinNotification winCallback) {
        return TilePtr(new Tile(row, col, 0, winValue, callback, winCallback));
    }

    bool MergeWith(Tile& other) {
        if (num != other.num) return false;
        num += other.num;
        other.num = 0;
        TriggerStatusCallback();
        other.TriggerStatusCallback();
        if (num >= winValue) winCallback();
        return true;
    }

    void Swap(Tile& other) {
        auto tmp = other.num;
        other.num = num;
        num = tmp;
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
    int winValue;
    TileStatusCallback statusCallback;
    WinNotification winCallback;

    void generateValue() {
        std::srand(clock());
        if (std::rand() % 4)
            num = 2;
        else
            num = 4;
    }
};
