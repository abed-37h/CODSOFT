#include <iostream>
#include "board.h"

board::board(void) {
    this->mBoard.assign(3, std::vector<char>(3, '#'));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->mBoard[i][j] = 3 * i + j + '1';
        }
    }

    this->occupied = 0;
}

void board::display(void) const {
    for (auto& r: this->mBoard) {
        std::cout << "\t\t[ ";
        for (auto& c : r) {
            std::cout << c << ' ';
        }
        std::cout << "]\n";
    }
    std::cout << '\n';
}

bool board::update(int x, int y, char mark) {
    if (x < 0 || x > 2 || y < 0 || y > 2 
        || this->mBoard[x][y] > '9' || this->mBoard[x][y] < '1') {
        return false;
    }

    this->mBoard[x][y] = mark;
    this->occupied++;
    return true;
}

bool board::checkWin(int x, int y) const {
    bool win = true;
    for (int i = 0; i < 3; i++) {
        if (this->mBoard[i][y] != this->mBoard[x][y]) win = false;
    }
    if (win) return true;

    win = true;
    for (int j = 0; j < 3; j++) {
        if (this->mBoard[x][j] != this->mBoard[x][y]) win = false;
    }
    if (win) return true;
    
    if (x == y) {
        win = true;
        for (int i = 0; i < 3; i++) {
            if (this->mBoard[i][i] != this->mBoard[x][y]) win = false;
        }
        if (win) return true;
    }
    else if (x + y == 2) {
        win = true;
        for (int i = 0; i < 3; i++) {
            if (this->mBoard[i][2 - i] != this->mBoard[x][y]) win = false;
        }
        if (win) return true;
    }

    return win;
}

bool board::full(void) const {
    return occupied == 9;
}
