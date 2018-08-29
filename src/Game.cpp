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

int Game::checkValue(const std::string & value)
{
    int value_;
    if ((value[0] == 'X') || (value[1] == '/'))
    {
        value_ = 10;
    }
    else
    {
        value_= ((value[0] - '0')+(value[1] - '0'));
    }

    return value_;
}
