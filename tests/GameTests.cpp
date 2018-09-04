#include <gtest/gtest.h>
#include "Game.hpp"

struct GameTests : public ::testing::Test
{

};

TEST_F(GameTests, name_should_be_empty_to_default_constructor)
{
    //GIVEN
    Game game;
    //THEN
    ASSERT_EQ("", game.getName());
}

TEST_F(GameTests, constructor_with_name_Adam)
{
    //GIVEN
    Game game("Adam");
    //THEN
    ASSERT_EQ("Adam", game.getName());
}

TEST_F(GameTests, set_Is_Strike_Or_Spare)
{
    //GIVEN
    Game game;
    //WHEN
    game.setIsStrikeOrSpare(1, "-/");
    game.setIsStrikeOrSpare(2, "X");
    //THEN
    ASSERT_TRUE(game.getFrame(2).isStrike());
    ASSERT_TRUE(game.getFrame(1).isSpare());
 }

TEST_F(GameTests, get_Frame)
{
    //GIVEN
    Game game;
    //WHEN
    Frame testingObject = game.getFrame(1);
    testingObject.addValue(5);
    //THEN
    ASSERT_EQ(5, testingObject.getValue());
}

TEST_F(GameTests, score_should_be_ten_strike)
{
    //GIVEN
    Game game;
    //WHEN
    int checkValue = game.checkValue("X ");
    //THEN
    ASSERT_EQ(10, checkValue);
}

TEST_F(GameTests, score_should_be_ten_spare)
{
    //GIVEN
    Game game;
    //WHEN
    int checkValue = game.checkValue("2/");
    //THEN
    ASSERT_EQ(10, checkValue);
}

TEST_F(GameTests, score_should_be_nine)
{
    //GIVEN
    Game game;
    //WHEN
    int checkValue = game.checkValue("45");
    //THEN
    ASSERT_EQ(9, checkValue);
}

TEST_F(GameTests, score_should_be_seven)
{
    //GIVEN
    Game game;
    //WHEN
    int checkValue = game.checkValue("-7");
    //THEN
    ASSERT_EQ(7, checkValue);
}

TEST_F(GameTests, score_should_be_three)
{
    //GIVEN
    Game game;
    //WHEN
    int checkValue = game.checkValue("3-");
    //THEN
    ASSERT_EQ(3, checkValue);
}

TEST_F(GameTests, first_ball_should_be_3_and_second_4)
{
    //GIVEN
    Game game;
    int firstBall, secondBall;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToInt("34");
    //THEN
    ASSERT_EQ(3, firstBall);
    ASSERT_EQ(4, secondBall);
}

TEST_F(GameTests, first_ball_should_be_10_and_second_0)
{
    //GIVEN
    Game game;
    int firstBall, secondBall;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToInt("X");
    //THEN
    ASSERT_EQ(10, firstBall);
    ASSERT_EQ(0, secondBall);
}

TEST_F(GameTests, first_ball_should_be_0_and_second_10)
{
    //GIVEN
    Game game;
    int firstBall, secondBall;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToInt("-/");
    //THEN
    ASSERT_EQ(0, firstBall);
    ASSERT_EQ(10, secondBall);
}

TEST_F(GameTests, frame_should_be_five)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(3, "5-");
    //THEN
    ASSERT_EQ(5, game.getFrame(3).getValue());
}

TEST_F(GameTests, prev_frame_should_be_15)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "2/");
    game.setValueFrameAndPrevFrames(1, "51");
    //THEN
    ASSERT_EQ(15, game.getFrame(0).getValue());
}

TEST_F(GameTests, frame0_should_be_30)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "X");
    game.setValueFrameAndPrevFrames(1, "X");
    game.setValueFrameAndPrevFrames(2, "X");
    //THEN
    ASSERT_EQ(30, game.getFrame(0).getValue());
}

TEST_F(GameTests, frame4_and_frame5_should_be_20)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(4, "X");
    game.setValueFrameAndPrevFrames(5, "-/");
    game.setValueFrameAndPrevFrames(6, "X");
    //THEN
    ASSERT_EQ(20, game.getFrame(4).getValue());
    ASSERT_EQ(20, game.getFrame(5).getValue());
}

TEST_F(GameTests, frame1_should_be_20_and_frame2_should_be_10)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(1, "X");
    game.setValueFrameAndPrevFrames(2, "6/");
    game.setValueFrameAndPrevFrames(3, "--");
    //THEN
    ASSERT_EQ(20, game.getFrame(1).getValue());
    ASSERT_EQ(10, game.getFrame(2).getValue());
}
