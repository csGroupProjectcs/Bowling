#pragma once
#include <string>
#include "Frame.hpp"

class Game
{
    std::string name_;
    
public:
    Frame frame_[12];

    explicit Game(const std::string & name = "");
    std::string getName() const;
    int score() const;
    void setIsStrikeOrSpare(unsigned short int position, const std::string& value);
};
