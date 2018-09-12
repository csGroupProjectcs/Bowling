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
    Game game4("Name4:7|9|X|X|5|X");
    Game game5("Name5:7|9|X|X|6/|9");
    Game game6("Name6:7|X|X|X");
    lane2.addGame(game4);
    lane2.addGame(game5);
    lane2.addGame(game6);
    bowling.addLane(lane2);
    Lane lane3;
    Game game7("Name7:7|9|X|X|6/|X|X|6|7|8");
    Game game8("Name8:7|9|X|X|8|9|3|6|7|8");
    Game game9("Name9:7|X|X|X|6/|8|3|6|X|8");
    Game game10("Name10:X|X|X|X|X|X|X|X|X|X||XX");
    lane3.addGame(game7);
    lane3.addGame(game8);
    lane3.addGame(game9);
    lane3.addGame(game10);
    bowling.addLane(lane3);
    std::stringstream ss;

    //WHEN
    bowling.writingDataToFile("saveToFileTest.txt");
    std::fstream dataTestIn;
    std::string dataFromFile;
    dataTestIn.open("../build/saveToFileTest.txt", std::ios::in);
    if (dataTestIn.is_open())
    {
            std::string line;
            while ( getline (dataTestIn, line) )
            {
               ss << line << "\n";
            }
    }
    dataFromFile = ss.str();
    std::string data = "### Lane 1: GAME STATUS ###\n### Lane 2: GAME STATUS ###\nName4 71\nName5 90\nName6 67\n### Lane 3: GAME STATUS ###\nName7 145\nName8 103\nName9 144\nName10 300\n";

    //THEN
    ASSERT_EQ(data, dataFromFile);
}
