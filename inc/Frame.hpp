#pragma once

class Frame
{
    int value_;
    bool isStrike;
    bool isSpare;
public:
    Frame();
    int getValue();
};
