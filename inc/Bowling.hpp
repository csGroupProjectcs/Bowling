#pragma once
#include <vector>
#include "Lane.hpp"

class Bowling
{
    int numberOfLanes_;
    std::vector<Lane> lanes_;
public:
    Bowling();
    int getNumberOfLanes() const;
};
