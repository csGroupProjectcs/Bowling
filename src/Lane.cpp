#include "Lane.hpp"
#include <stdexcept>

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
    if (number < 0 || number >=numberOfGames_)
    {
        std::string message = "The number of games should be between 0 and " + std::to_string(numberOfGames_ - 1);
        throw std::out_of_range(message);
    }
    return games_[number];
}

std::string Lane::getStatusLane() const
{
	if (numberOfGames_ == 0)
	{
		return "No games";
	}
	if (numberOfGames != 0)
	{
		return getGame(0).getStatus();
	}
	
}
