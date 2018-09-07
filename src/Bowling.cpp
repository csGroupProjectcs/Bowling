#include "Bowling.hpp"

Bowling::Bowling() : numberOfLanes_(0) {}

int Bowling::getNumberOfLanes() const
{
        return numberOfLanes_;
}

void Bowling::addLane(Lane lane)
{
    numberOfLanes_++;
    lanes_.push_back(lane);
}

Lane Bowling::getLane(int number) const
{
    return lanes_[number];
}
