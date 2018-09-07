#pragma once
#include <vector>
#include "Game.hpp"

class Lane
{
    int numberOfGames_;
    std::vector<Game> lanes_;
public:
    Lane();
    void addGame(Game game);
    Game getGame(int number) const;
    int getNumberOfGames() const;
};
