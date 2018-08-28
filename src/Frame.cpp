#include "../inc/Frame.hpp"

Frame::Frame() : value_(0), isStrike_(false), isSpare_(false)
{}

void Frame::setValue(int value)
{
    value_ = value;
}

int Frame::getValue()
{
    return value_;
}

bool Frame::isStrike()
{
    return isStrike_;
}

void Frame::setIsStrike()
{
    isStrike_ = true;
}

bool Frame::isSpare()
{
    return isSpare_;
}

void Frame::setIsSpare()
{
    isSpare_ = true;
}
