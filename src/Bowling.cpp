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
    for (int i = 0; i < getNumberOfLanes(); i++)
    {
        ss << "### Lane " << i+1 << ": " << "GAME STATUS" << " ###\n"; // game status method is needed

        for (int x = 0; x < getLane(i).getNumberOfGames(); x++)
        {
            ss << getLane(i).getGame(x).getName() << " " << getLane(i).getGame(x).score() << "\n";
        }
    }
    return ss.str();
}

void Bowling::print() const
{
    std::cout << toString();
}
