#pragma once
#include <vector>
#include "Game.hpp"

class Lane
{
    int numberOfGames_;
    std::vector<Game> games_;
public:
    Lane();
    void addGame(Game game);
    Game getGame(int number) const;
    int getNumberOfGames() const;
    std::string getStatusLane() const;
};
