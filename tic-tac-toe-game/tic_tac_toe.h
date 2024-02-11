#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include "player.h"
#include "board.h"

enum status {
    win,
    draw,
    ongoing,
    invalid
};

class tic_tac_toe {
public:
    tic_tac_toe(std::string player1Name, std::string player2Name, bool xo);
    status playTurn(int pos);
    player currentPlayer(void) const;
private:
    player player1;
    player player2;
    board gameBoard;
    bool turn;
};

#endif