#include "player.h"

player::player(void) = default;

player::player(std::string name, char mark)
{
    this->name = name;
    this->mark = mark;
}

std::string player::getName(void) const{
    return this->name;
}

char player::getMark(void) const {
    return this->mark;
}
