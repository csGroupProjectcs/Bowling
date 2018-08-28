#include "../inc/Frame.hpp"

Frame::Frame() : value_(0), isStrike_(false), isSpare_(false)
{}

void Frame::addValue(int value)
{
    value_ += value;
}

int Frame::getValue() const
{
    return value_;
}

bool Frame::isStrike() const
{
    return isStrike_;
}

void Frame::setIsStrike()
{
    isStrike_ = true;
}

bool Frame::isSpare() const
{
    return isSpare_;
}

void Frame::setIsSpare()
{
    isSpare_ = true;
}
