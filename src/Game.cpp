#include "Game.hpp"
#include <algorithm>

Game::Game(const std::string & name) : name_(name)
{}

std::string Game::getName() const
{
    return name_;
}

int Game::score() const
{
    //needs implementation after made checkValueFrame()
    return 0;
}

void Game::setIsStrikeOrSpare(unsigned short int position, const std::string& value)
{
    auto strike = std::find(value.begin(), value.end(), 'X');
    auto spare = std::find(value.begin(), value.end(), '/');
    if (*strike == 'X')
    {
        frame_[position].setIsStrike();
    }
    if (*spare == '/')
    {
        frame_[position].setIsSpare();
    }
}
