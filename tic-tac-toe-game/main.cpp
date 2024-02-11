#include <iostream>
#include "tic_tac_toe.h"

void playGame(void);

int main() {
    while (true) {
        playGame();

        bool playAgain;
        std::cout << "Play again? [1:yes, 0:no] ";
        std::cin >> playAgain;
        if (!playAgain) {
            system("clear");
            break;
        }
    }
}

void playGame(void) {
    std::string player1Name, player2Name;
    bool xo;

    std::cout << "Player1: ";
    std::cin >> player1Name;

    std::cout << "Player2: ";
    std::cin >> player2Name;

    std::cout << "\t[1] " << "X:" << player1Name << '\t' << "O:" << player2Name << "\n";
    std::cout << "\t[0] " << "O:" << player1Name << '\t' << "X:" << player2Name << "\n";
    std::cout << "Choose combination: ";
    std::cin >> xo;

    system("clear");

    tic_tac_toe game(player1Name, player2Name, xo);
    
    while (true) {
        player currentPlayer = game.currentPlayer();
        std::cout << "\t" << currentPlayer.getName() << "'s turn with " << currentPlayer.getMark() << "\n";
        int pos;
        std::cout << "Position: ";
        std::cin >> pos;

        system("clear");
        
        switch (game.playTurn(pos)) {
        case win: std::cout << currentPlayer.getName() << " wins.\n"; return;
        case draw: std::cout << "\tDraw\n"; return;
        case invalid: std::cout << "\tInvalid position! Play again.\n";
        case ongoing: std::cout << "Ongoing: "; break;
        }
    }
}