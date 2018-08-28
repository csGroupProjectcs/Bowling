#pragma once
#include <string>

class Game
{
    std::string name_;
public:
    std::string getName() const;
    void setName(const std::string &);
};
