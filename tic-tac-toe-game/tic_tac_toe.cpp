#include <iostream>
#include "tic_tac_toe.h"

tic_tac_toe::tic_tac_toe(std::string player1Name, std::string player2Name, bool xo) {
    if (xo) {
        this->player1 = player(player1Name, 'X');
        this->player2 = player(player2Name, 'O');
        this->turn = true;
    }
    else {
        this->player1 = player(player1Name, 'O');
        this->player2 = player(player2Name, 'X');
        this->turn = false;
    }
    std::cout << "\n\t";
    std::cout << player1.getName() << ": " << player1.getMark() << "\t\t";
    std::cout << player2.getName() << ": " << player2.getMark() << "\n\n";
    this->gameBoard.display();
}

status tic_tac_toe::playTurn(int pos) {
    int x = (pos - 1) / 3;
    int y = (pos - 1) % 3;
    char mark = (this->turn ? this->player1.getMark() : this->player2.getMark());
    bool valid = this->gameBoard.update(x, y, mark);

    std::cout << "\t";
    std::cout << player1.getName() << ": " << player1.getMark() << "\t\t";
    std::cout << player2.getName() << ": " << player2.getMark() << "\n\n";
    this->gameBoard.display();

    if (valid) {
        turn = !turn;
        return this->gameBoard.checkWin(x, y) ? win : this->gameBoard.full() ? draw : ongoing;
    }

    return invalid;
}

player tic_tac_toe::currentPlayer(void) const {
    return this->turn ? this->player1 : this->player2;
}
