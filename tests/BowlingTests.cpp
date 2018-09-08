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

TEST_F(BowlingTests, add_1_lane_with_1_game_Adam_expect_NumberOfLanes_1_and_name_game_Adam)
{
    //WHEN
    Game game("Adam");
    Lane lane;
    lane.addGame(game);
    bowling.addLane(lane);
    //THEN
    ASSERT_EQ(1, bowling.getNumberOfLanes());
    ASSERT_EQ("Adam", bowling.getLane(0).getGame(0).getName());
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

TEST_F(BowlingTests, when_read_directory_data_tests_expect_numberOfLanes_2_name_Sandra_in_lane_2_in_game_2_and_message_Wrong_file)
{
    //WHEN
    testing::internal::CaptureStdout();
    bowling.readDirectory("../tests/data_tests");
    std::string output = testing::internal::GetCapturedStdout();
    //THEN
    ASSERT_EQ(2, bowling.getNumberOfLanes());
    ASSERT_EQ("Sandra", bowling.getLane(1).getGame(1).getName());
    ASSERT_EQ("Wrong file\n", output);
}
