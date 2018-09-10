#include "Bowling.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
Bowling::Bowling() : numberOfLanes_(0) {}

int Bowling::getNumberOfLanes() const
{
        return numberOfLanes_;
}

void Bowling::addLane(Lane lane)
{
    numberOfLanes_++;
    lanes_.push_back(lane);
}

Lane Bowling::getLane(int number) const
{
    if (number < 0 || number >= numberOfLanes_)
    {
        std::string message = "The number of lane should be in range 0 to " + std::to_string(numberOfLanes_ - 1);
        throw std::out_of_range(message);
    }
    return lanes_[number];
}

void Bowling::readDirectory(path p)
{
    try
    {
        if (is_directory(p))
        {
            std::vector<path> v;
            for (auto&& x : directory_iterator(p))
                v.push_back(x.path());
            std::sort(v.begin(), v.end());
            for (auto&& x : v)
            {
                if (is_regular_file(x))
                {
                    Lane lane;
                    ifstream file {x};
                    std::string packedData;
                    while (std::getline(file, packedData))
                    {
                        Game game(packedData);
                        lane.addGame(game);
                    }
                    addLane(lane);
                    file.close();
                } else
                {
                    std::cout << "Wrong file" << std::endl;
                }
            }
        } else
        {
            std::cout << "Wrong directory" << std::endl;
        }
    }
    catch (const filesystem_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

std::string Bowling::toString() const
{
    std::stringstream ss;
    std::string data;
    for (int i = 0; i < getNumberOfLanes(); i++)
    {
        Lane lane = getLane(0);
        std::string laneData;
        std::stringstream no; 
        no << ++i;
        std::string numberOfLane = no.str();
            laneData.insert(laneData.size(), "### Lane ");
            laneData.insert(laneData.size(), numberOfLane);
            laneData.insert(laneData.size(), ": ");
            laneData.insert(laneData.size(), "GAME STATUS"); // game status method is needed
            laneData.insert(laneData.size(), " ###\n");
        std::string namesAndScore;
        for (int i = 0; i < lane.getNumberOfGames(); i++)
        {
            std::stringstream scr;
            scr << lane.getGame(i).score();
            std::string score = scr.str();
            namesAndScore.insert(namesAndScore.size(), lane.getGame(i).getName());
            namesAndScore.insert(namesAndScore.size(), " ");
            namesAndScore.insert(namesAndScore.size(), score);
            namesAndScore.insert(namesAndScore.size(), "\n");
        }
        data.insert(data.size(), laneData);
        data.insert(data.size(), namesAndScore);
    }
    ss << data;
    return ss.str();
}