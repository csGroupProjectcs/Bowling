#include "Game.hpp"
#include <algorithm>
#include <tuple>
#include <sstream>
#include <iostream>

Game::Game() {}

Game::Game(const std::string& framesOfOneGame) : frameCounter_(0)
{
    std::stringstream frames(framesOfOneGame);
    std::string oneFrame;
    std::string bonusBalls;
    getline(frames, name_, ':');
    for (int framePos = 0; framePos < 10 and getline(frames, oneFrame, '|'); framePos++)
    {
        setValueFrameAndPrevFrames(framePos, oneFrame);
    }
    if (getline(frames, oneFrame, '|'))
    {
        if (getline(frames, bonusBalls))
        {
            if(bonusBalls.size() == 2)
            {
                setValueFrameAndPrevFrames(10, bonusBalls.substr(0, 1));
                setValueFrameAndPrevFrames(11, bonusBalls.substr(1, 1));
            }
            else if(bonusBalls.size() == 1)
            {
                setValueFrameAndPrevFrames(10, bonusBalls.substr(0, 1));
            }
        }
    }
}

std::string Game::getName() const
{
    return name_;
}

int Game::score() const
{
    int partialScore = 0;
    for (int i = 0; i < 10; i++)
    {
        partialScore += frame_[i].getValue();
    }
    return partialScore;
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

std::pair <int, int> Game::convertValueToPairOfInts(const std::string& value)
{
    int firstBall = 0;
    int secondBall = 0;

    auto valueTemp = value;
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
    if(value.size() == 2 or value == "X" or pos>9) frameCounter_++; 

    int firstBall, secondBall;
    std::tie(firstBall, secondBall) = convertValueToPairOfInts(value);

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

bool Game::getStatusGame()
{
    int numberOfFrames = 10;
    if (frame_[9].isSpare()) numberOfFrames = 11;
    else if (frame_[9].isStrike()) numberOfFrames = 12;
    if (frameCounter_ == numberOfFrames)
        return true;
    else return false;
}
