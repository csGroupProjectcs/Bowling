#include "Bowling.hpp"
#include <iostream>

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
