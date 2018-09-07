#include "Game.hpp"
#include <algorithm>
#include <tuple>
#include <sstream>

Game::Game() {}

Game::Game(const std::string& framesOfOneGame)
{
    std::stringstream frames;
    frames << framesOfOneGame;
    getline(frames, name_, ':');
}

std::string Game::getName() const
{
    return name_;
}

int Game::score() const
{
    //needs implementation after made checkValueFrame()
    return 0;
}

void Game::setIsStrikeOrSpare(unsigned short int position, const std::string& value)
{
    if (value[0] == 'X')
    {
        frame_[position].setIsStrike();
    }
    if (value.size() == 2 and value[1] == '/')
    {
        frame_[position].setIsSpare();
    }
}

std::pair <int, int> Game::checkValue(const std::string& value)
{
    int firstBall = 0;
    int secondBall = 0;

    auto valueTemp = value.substr(0, 2);
    std::replace(valueTemp.begin(), valueTemp.end(), '-', '0');
    
    if (value.size() == 1)
    {
        if (value[0] == 'X') firstBall = 10;
        else firstBall = std::stoi(valueTemp.substr(0, 1));
    }
    else if (value.size() == 2)
    {
        if (value[1] == '/') 
        {
            firstBall = std::stoi(valueTemp.substr(0, 1));
            secondBall = 10 - firstBall;
        }
        else
        {
            firstBall = std::stoi(valueTemp.substr(0, 1));
            secondBall = std::stoi(valueTemp.substr(1, 1));
        }
    }

    return std::make_pair(firstBall, secondBall);
}

Frame Game::getFrame(unsigned short int position)
{
    return frame_[position];
}

void Game::setValueFrameAndPrevFrames(int pos, const std::string& value)
{
    int firstBall, secondBall;
    std::tie(firstBall, secondBall) = checkValue(value);

    frame_[pos].setValue(firstBall + secondBall);
    setIsStrikeOrSpare(pos, value);
    
    if (pos < 10)
    {
        if (pos > 0 and frame_[pos - 1].isStrike())
        {
            frame_[pos - 1].addValue(firstBall + secondBall);
        }
        if( pos > 1 and frame_[pos - 2].isStrike() and frame_[pos - 1].isStrike())
        {
            frame_[pos - 2].addValue(firstBall);
        }
        if (pos > 0 and frame_[pos - 1].isSpare())
        {
            frame_[pos - 1].addValue(firstBall);
        }
    }
    else
    {
        if (frame_[pos - 1].isStrike() or frame_[pos - 1].isSpare())
        {
            frame_[pos - 1].addValue(firstBall);
        }
        if (frame_[pos - 2].isStrike() )
        {
            frame_[pos - 2].addValue(firstBall);
        }
    }
}
