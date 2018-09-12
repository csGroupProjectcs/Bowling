#include <gtest/gtest.h>
#include "Bowling.hpp"

struct BowlingTests : public ::testing::Test
{
    //GIVEN
    Bowling bowling;
};

TEST_F(BowlingTests, toString_compare_given_data_and_shown_data_expect_return_true)
{
    //GIVEN
    Lane lane1;
    Game game1("Name:7|9|X|X|6/|7|3|6|7|8");
    lane1.addGame(game1);
    bowling.addLane(lane1);
    //WHEN
    std::string data = "### Lane 1: GAME STATUS ###\nName 110\n";
    std::string dataFromMethod = bowling.toString();
    //THEN
    ASSERT_EQ(data, dataFromMethod);
}

TEST_F(BowlingTests, toString_compare_empty_lane_and_shown_data_expect_return_true)
{
    //GIVEN
    Lane lane1;
    bowling.addLane(lane1);
    //WHEN
    std::string data = "### Lane 1: GAME STATUS ###\n";
    std::string dataFromMethod = bowling.toString();
    //THEN
    ASSERT_EQ(data, dataFromMethod);
}

TEST_F(BowlingTests, toString_compare_many_empty_lanes_and_shown_data_expect_return_true)
{
    //GIVEN
    Lane lane1;
    Lane lane2;
    Lane lane3;
    bowling.addLane(lane1);
    bowling.addLane(lane2);
    bowling.addLane(lane3);
    //WHEN
    std::string data = "### Lane 1: GAME STATUS ###\n### Lane 2: GAME STATUS ###\n### Lane 3: GAME STATUS ###\n";
    std::string dataFromMethod = bowling.toString();
    //THEN
    ASSERT_EQ(data, dataFromMethod);
}

TEST_F(BowlingTests, toString_compare_many_games_and_shown_data_expect_return_true)
{
    //GIVEN
    Lane lane1;
    Game game1("Name1:7|9|X|X|6/|X|3|6|7|8");
    Game game2("Name2:7|9|X|X|6/|9|3|6|7|8");
    Game game3("Name3:7|X|X|X|6/|8|3|6|X|8");
    lane1.addGame(game1);
    lane1.addGame(game2);
    lane1.addGame(game3);
    bowling.addLane(lane1);

    //WHEN
    std::string data = "### Lane 1: GAME STATUS ###\nName1 119\nName2 114\nName3 144\n";
    std::string dataFromMethod = bowling.toString();
    //THEN
    ASSERT_EQ(data, dataFromMethod);

}

TEST_F(BowlingTests, toString_compare_given_data_to_many_lanes_and_many_games_and_shown_data_expect_return_true)
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

    //WHEN
    std::string data = "### Lane 1: GAME STATUS ###\n### Lane 2: GAME STATUS ###\nName4 71\nName5 90\nName6 67\n### Lane 3: GAME STATUS ###\nName7 145\nName8 103\nName9 144\nName10 300\n";
    std::string dataFromMethod = bowling.toString();
    //THEN
    ASSERT_EQ(data, dataFromMethod);

}
