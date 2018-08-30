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

int Game::checkValue(const std::string & value)
{
    int valueInt;
    auto valueTemp=value.substr(0,2);
    if ((value[0] == 'X') || (value[1] == '/'))
    {
        valueInt = 10;
    }
    else
    {
        std::replace(valueTemp.begin(), valueTemp.end(), '-', '0');
        valueInt= (std::stoi(valueTemp.substr(0,1)))+(std::stoi(valueTemp.substr(1,1)));
    }

    return valueInt;
}
