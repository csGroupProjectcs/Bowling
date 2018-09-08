#pragma once
#include <string>
#include <algorithm>
#include <utility>
#include "Frame.hpp"

class Game
{
    std::string name_;
    Frame frame_[12];
public:
    Game();
    explicit Game(const std::string& oneLine);
    std::string getName() const;
    int score() const;
    std::pair <int, int> convertValueToPairOfInts(const std::string& value);
    void setIsStrikeOrSpare(unsigned short int position, const std::string& value);
    Frame getFrame(unsigned short int position);
    void setValueFrameAndPrevFrames(int pos, const std::string& value);
};
