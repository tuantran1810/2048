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
            auto tile = Tile::CreateTile(i, j, winValue,
                [&] (int row, int col, bool containNumber) {
                    int index = row * 4 + col;
                    if (containNumber) {
                        std::set<int>::iterator it = blankTiles.find(index);
                        if (it != blankTiles.end()) blankTiles.erase(it);
                        return;
                    }
                    blankTiles.insert(index);
                },
                [=](){
                    this->winNotification();
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

bool
BoardGame::OnLeftKey() {
    for (auto& row : rows)
        row.MergeLeft();
    return onAfterMove();
}

bool
BoardGame::OnRightKey() {
    for (auto& row : rows)
        row.MergeRight();
    return onAfterMove();
}

bool
BoardGame::OnUpKey() {
    for (auto& col : cols)
        col.MergeUp();
    return onAfterMove();
}

bool
BoardGame::OnDownKey() {
    for (auto& col : cols)
        col.MergeDown();
    return onAfterMove();
}

void
BoardGame::End() {
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

bool
BoardGame::onAfterMove() {
    if (!throwNumberToTile()) {
        return false;
    }
    return true;
}

std::ostream& operator<< (std::ostream& out, const BoardGame &boardGame) {
    for (auto& row : boardGame.rows)
        out << row << std::endl;
    return out;
}
