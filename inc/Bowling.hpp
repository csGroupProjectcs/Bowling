#pragma once
#include <vector>
#include "Lane.hpp"
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
using namespace boost::filesystem;

class Bowling
{
    int numberOfLanes_;
    std::vector<Lane> lanes_;
public:
    Bowling();
    int getNumberOfLanes() const;
    void addLane(Lane lane);
    Lane getLane(int number) const;
    void readDirectory(path p);
};
