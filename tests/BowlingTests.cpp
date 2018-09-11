#include <gtest/gtest.h>
#include "Bowling.hpp"

struct BowlingTests : public ::testing::Test
{
    //GIVEN
    Bowling bowling;
};

TEST_F(BowlingTests, check_if_inicial_NumberOfLanes_is_zero)
{
    //THEN
    ASSERT_EQ(0, bowling.getNumberOfLanes());
}

TEST_F(BowlingTests, add_1_lane_expect_NumberOfLanes_1)
{
    //WHEN
    Lane lane;
    bowling.addLane(lane);
    //THEN
    ASSERT_EQ(1, bowling.getNumberOfLanes());
}

TEST_F(BowlingTests, add_1_lane_with_1_game_Adam_X_2_expect_NumberOfLanes_1_name_game_Adam_score_14)
{
    //WHEN
    Game game("Adam:X|2");
    Lane lane;
    lane.addGame(game);
    bowling.addLane(lane);
    //THEN
    ASSERT_EQ(1, bowling.getNumberOfLanes());
    ASSERT_EQ("Adam", bowling.getLane(0).getGame(0).getName());
    ASSERT_EQ(14, bowling.getLane(0).getGame(0).score());
}

TEST_F(BowlingTests, when_directory_to_read_no_existe_expect_in_stdout_message_Wrong_directory)
{
    //WHEN
    testing::internal::CaptureStdout();
    bowling.readDirectory("asdfsa");
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ("Wrong directory\n", output);
}

TEST_F(BowlingTests, when_read_directory_data_tests_expect_numberOfLanes_3_in_lane_2_in_game_2_expect_name_Sandra_score_16)
{
    //WHEN
    bowling.readDirectory("../tests/data_tests");
    //THEN
    ASSERT_EQ(3, bowling.getNumberOfLanes());
    ASSERT_EQ("Sandra", bowling.getLane(1).getGame(1).getName());
    ASSERT_EQ(16, bowling.getLane(1).getGame(1).score());
}

TEST_F(BowlingTests, when_read_empty_file_in_lane_3_expect_NumberOfGames_0)
{
    //WHEN
    bowling.readDirectory("../tests/data_tests");
    //THEN
    ASSERT_EQ(0, bowling.getLane(2).getNumberOfGames());
}

TEST_F(BowlingTests, when_read_directory_and_get_lane_out_of_range_expect_throw)
{
    //WHEN
    bowling.readDirectory("../tests/data_tests");
    //THEN
    ASSERT_THROW(bowling.getLane(48), std::out_of_range);
}

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
    Game game1("Name1:7|9|X|X|6/|3|3|6|7|8");
    Game game2("Name2:7|9|X|X|6/|9|3|6|7|8");
    Game game3("Name3:7|X|X|X|7|8|3|6|X|8");
    lane1.addGame(game1);
    lane1.addGame(game2);
    lane1.addGame(game3);
    bowling.addLane(lane1);
    Lane lane2;
    Game game4("Name1:7|9|X|X|5|X|3|6|7|8");
    Game game5("Name2:7|9|X|X|6/|9|3|6|7|8");
    Game game6("Name3:7|X|X|X|1|8|3|6|X|8");
    lane2.addGame(game4);
    lane2.addGame(game5);
    lane2.addGame(game6);
    bowling.addLane(lane2);
    Lane lane3;
    Game game7("Name1:7|9|X|X|6/|X|X|6|7|8");
    Game game8("Name2:7|9|X|X|8|9|3|6|7|8");
    Game game9("Name3:7|X|X|X|6/|8|3|6|X|8");
    lane3.addGame(game7);
    lane3.addGame(game8);
    lane3.addGame(game9);
    bowling.addLane(lane3);

    //WHEN
    std::string data = "### Lane 1: GAME STATUS ###\nName1 102\nName2 114\nName3 131\n### Lane 2: GAME STATUS ###\nName1 102\nName2 114\nName3 131\n### Lane 3: GAME STATUS ###\nName1 102\nName2 114\nName3 131\n";
    std::string dataFromMethod = bowling.toString();
    //THEN
    ASSERT_EQ(data, dataFromMethod);

}
