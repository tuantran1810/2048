#include <cstdlib>
#include <iostream>
#include <functional>
#include <iomanip>
#include <ctime>
#include "tile.h"

std::ostream& operator<< (std::ostream& out, const Tile& tile) {
    if (tile.ContainNumber())
        out << std::setw(6) << std::right << tile.num;
    else
        out << std::setw(6) << std::right << '.';
    return out;
}
