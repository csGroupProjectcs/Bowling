#pragma once
#include <vector>
#include "Game.hpp"

class Lane
{
    int numberOfGames_;
    std::vector<Game> lanes_;
public:
    Lane();
    int getNumberOfGames() const;
};
