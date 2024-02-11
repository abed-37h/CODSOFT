#ifndef BOARD
#define BOARD

#include <vector>

class board {
public:
    board(void);
    void display(void) const;
    bool update(int x, int y, char mark);
    bool checkWin(int x, int y) const;
    bool full(void) const;
private:
    std::vector<std::vector<char>> mBoard;
    int occupied;
};

#endif