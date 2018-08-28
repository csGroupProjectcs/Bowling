#include "../inc/Game.hpp"

std::string Game::getName() const
{
    return name_;
}

void Game::setName(const std::string & name)
{
    name_ = name;
}

int Game::score() const
{
    //needs implementation after made checkValueFrame()
    return 0;
}
