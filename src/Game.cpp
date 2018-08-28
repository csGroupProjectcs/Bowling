#include "../inc/Game.hpp"

std::string Game::getName() const
{
    return name_;
}

void Game::setName(const std::string & name)
{
    name_ = name;
}
