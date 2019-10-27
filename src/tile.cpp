#include <cstdlib>
#include <iostream>
#include <functional>
#include <iomanip>
#include <ctime>
#include "tile.h"

Painter* Painter::instance = nullptr;

std::ostream& operator<< (std::ostream& out, const Tile& tile) {
    Painter* painter = Painter::GetInstance();
    if (tile.ContainNumber())
        out << painter->GetColor(tile.num) << std::setw(6) << std::right << tile.num;
    else
        out << painter->GetColor(tile.num) << std::setw(6) << std::right << '.';
    return out;
}
