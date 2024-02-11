#ifndef PLAYER
#define PLAYER

#include <string>

class player {
public:
    player(void);
    player(std::string name, char mark);
    std::string getName(void) const;
    char getMark(void) const;
private:
    std::string name;
    char mark;
};

#endif