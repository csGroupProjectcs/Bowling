#include "../inc/Game.hpp"

Game::Game(const std::string & name)
{
    name_ = name;
}

std::string Game::getName() const
{
    return name_;
}

int Game::score() const
{
    //needs implementation after made checkValueFrame()
    return 0;
}
