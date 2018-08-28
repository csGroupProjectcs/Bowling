#include "../inc/Frame.hpp"

Frame::Frame() : value_(0)
{

}

void Frame::setValue(int value)
{
    value_ = value;
}

int Frame::getValue()
{
    return value_;
}
