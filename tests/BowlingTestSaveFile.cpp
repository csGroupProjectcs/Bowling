#include <gtest/gtest.h>
#include "Bowling.hpp"
#include <fstream>

struct BowlingTests : public ::testing::Test
{
    //GIVEN
    Bowling bowling;
};

TEST_F (BowlingTests, testing_saving_data_are_equal_to_expect_data_return_true)
{
    //GIVEN
    Lane lane1;
    bowling.addLane(lane1);
    Lane lane2;
    Game game4("Name4:72|91|X|X|51|X");
    Game game5("Name5:71|91|X|X|6/|91");
    Game game6("Name6:71|X|X|X");
    lane2.addGame(game4);
    lane2.addGame(game5);
    lane2.addGame(game6);
    bowling.addLane(lane2);
    Lane lane3;
    Game game7("Name7:71|91|X|X|6/|X|X|62|71|81");
    Game game8("Name8:7-|9-|X|X|81|9-|35|62|72|81");
    Game game9("Name9:71|X|X|X|6/|82|34|61|X|81");
    Game game10("Name10:X|X|X|X|X|X|X|X|X|X||XX");
    lane3.addGame(game7);
    lane3.addGame(game8);
    lane3.addGame(game9);
    lane3.addGame(game10);
    bowling.addLane(lane3);
    std::stringstream ss;
    const static std::string data {"### Lane 1: no game ###\n### Lane 2: game in progress ###\nName4 76\nName5 93\nName6 68\n### Lane 3: game finished ###\nName7 153\nName8 115\nName9 154\nName10 300\n"};

    //WHEN
    bowling.writingDataToFile("saveToFileTest.txt");
    std::fstream dataTestIn;
    dataTestIn.open("saveToFileTest.txt", std::ios::in);
    if (dataTestIn.is_open())
    {
            std::string line;
            while ( getline (dataTestIn, line) )
            {
               ss << line << "\n";
            }
    }
    const static std::string dataFromFile = ss.str();

    //THEN
    ASSERT_EQ(data, dataFromFile);
}
