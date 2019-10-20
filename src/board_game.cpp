#include "board_game.h"

void
BoardGame::Init() {
    tiles.clear();
    rows.clear();
    cols.clear();

    rows.resize(numOfRow);
    cols.resize(numOfCol);

    for (int i = 0; i < numOfRow; i++) {
        for (int j = 0; j < numOfCol; j++) {
            auto tile = Tile::CreateTile(i, j,
                [&] (int row, int col, bool containNumber) {
                    int index = row * 4 + col;
                    if (containNumber) {
                        std::set<int>::iterator it = blankTiles.find(index);
                        if (it != blankTiles.end()) blankTiles.erase(it);
                        return;
                    }
                    blankTiles.insert(index);
                });
            auto tile1 = tile;
            auto tile2 = tile;
            tiles.push_back(std::move(tile));
            rows[i].push_back(std::move(tile1));
            cols[j].push_back(std::move(tile2));
            blankTiles.insert(i*4 + j);
        }
    }
}

void
BoardGame::Start() {
    throwNumberToTile();
    throwNumberToTile();
}

void BoardGame::End() {
    tiles.clear();
    rows.clear();
    cols.clear();
}

bool
BoardGame::throwNumberToTile() {
    if (blankTiles.empty()) return false;
    int index = randomIndex(blankTiles.size());
    auto it = blankTiles.begin();
    for (int i = 0; i < index; i++, it++) {}
    if (tiles[*it] != nullptr) {
        tiles[*it]->ThrowNumber();
        return true;
    }
    return false;
}

std::ostream& operator<< (std::ostream& out, const BoardGame &boardGame) {
    for (auto& row : boardGame.rows)
        out << row << std::endl;
    return out;
}
