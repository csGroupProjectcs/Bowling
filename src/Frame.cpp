#include "../inc/Frame.hpp"

Frame::Frame() : value_(0), isStrike_(false)
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
