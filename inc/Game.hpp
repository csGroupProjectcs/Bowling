#pragma once
#include <string>
#include "../inc/Frame.hpp"

class Game
{
    std::string name_;
    Frame frame[12];
public:
    std::string getName() const;
    void setName(const std::string &);
    int score() const;
    int checkValue(const std::string & value);
    void checkIsStrikeOrSpare(int pos, const std::string & value);
    void setValueFrameAndPrevFrames(int pos, const std::string & value);
};
