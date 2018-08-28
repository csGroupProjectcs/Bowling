#pragma once

class Frame
{
    int value_;
    bool isStrike_;
    bool isSpare_;
public:
    Frame();
    int getValue();
    void setValue(int value);
    bool isStrike();
    void setIsStrike();
    bool isSpare();
};
