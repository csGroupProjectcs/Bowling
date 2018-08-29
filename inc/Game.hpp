#pragma once
#include <string>
#include "../inc/Frame.hpp"

class Game
{
    std::string name_;
    Frame frame[12];
public:
    Game(const std::string & name = "");
    std::string getName() const;
    int score() const;
    int checkValue(const std::string & value);
    void checkIsStrikeOrSpare(int pos, const std::string & value);
    void setValueFrameAndPrevFrames(int pos, const std::string & value);
};
