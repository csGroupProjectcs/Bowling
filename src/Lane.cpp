#include "Lane.hpp"

Lane::Lane() : numberOfGames_(0) {}

int Lane::getNumberOfGames() const
{
   return numberOfGames_;
}

void Lane::addGame(Game game)
{
    numberOfGames_++;
    games_.push_back(game);
}

Game Lane::getGame(int number) const
{
    return games_[number];
}
