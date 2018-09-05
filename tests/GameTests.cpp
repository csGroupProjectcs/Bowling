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
    int firstBall, secondBall, score;
    //WHEN
    std::tie(firstBall, secondBall) = game.checkValue("X");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(10, score);
}

TEST_F(GameTests, score_should_be_ten_spare)
{
    //GIVEN
    Game game;
    int firstBall, secondBall, score;
    //WHEN
    std::tie(firstBall, secondBall) = game.checkValue("2/");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(10, score);
}

TEST_F(GameTests, score_should_be_nine)
{
    //GIVEN
    Game game;
    int firstBall, secondBall, score;
    //WHEN
    std::tie(firstBall, secondBall) = game.checkValue("45");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(9, score);
}

TEST_F(GameTests, score_should_be_seven)
{
    //GIVEN
    Game game;
    int firstBall, secondBall, score;
    //WHEN
    std::tie(firstBall, secondBall) = game.checkValue("-7");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(7, score);
}

TEST_F(GameTests, score_should_be_three)
{
    //GIVEN
    Game game;
    int firstBall, secondBall, score;
    //WHEN
    std::tie(firstBall, secondBall) = game.checkValue("3-");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(3, score);
}

TEST_F(GameTests, first_ball_should_be_3_and_second_4)
{
    //GIVEN
    Game game;
    int firstBall, secondBall;
    //WHEN
    std::tie(firstBall, secondBall) = game.checkValue("34");
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
    std::tie(firstBall, secondBall) = game.checkValue("X");
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
    std::tie(firstBall, secondBall) = game.checkValue("-/");
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

TEST_F(GameTests, frame0_and_frame1_should_be_20)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "X");
    game.setValueFrameAndPrevFrames(1, "-/");
    game.setValueFrameAndPrevFrames(2, "X");
    //THEN
    ASSERT_EQ(20, game.getFrame(0).getValue());
    ASSERT_EQ(20, game.getFrame(1).getValue());
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

TEST_F(GameTests, frame0_should_be_14_and_frame1_should_be_7)
{
    //GIVEN
    Game game;
    std::string frame0 = "X";
    std::string frame1 = "34";
    //WHEN
    game.setValueFrameAndPrevFrames(0, frame0);
    game.setValueFrameAndPrevFrames(1, frame1);
    //THEN
    ASSERT_EQ(17, game.getFrame(0).getValue());
    ASSERT_EQ(7, game.getFrame(1).getValue());
}

TEST_F(GameTests, frame0_should_be_7_and_frame1_should_be_4)
{
    //GIVEN
    Game game;
    std::string frame0 = "34";
    std::string frame1 = "4";
    //WHEN
    game.setValueFrameAndPrevFrames(0, frame0);
    game.setValueFrameAndPrevFrames(1, frame1);
    //THEN
    ASSERT_EQ(7, game.getFrame(0).getValue());
    ASSERT_EQ(4, game.getFrame(1).getValue());
}

TEST_F(GameTests, value_of_first_8_frames_should_be_30_frame9_21_fram10_16)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "X");
    game.setValueFrameAndPrevFrames(1, "X");
    game.setValueFrameAndPrevFrames(2, "X");
    game.setValueFrameAndPrevFrames(3, "X");
    game.setValueFrameAndPrevFrames(4, "X");
    game.setValueFrameAndPrevFrames(5, "X");
    game.setValueFrameAndPrevFrames(6, "X");
    game.setValueFrameAndPrevFrames(7, "X");
    game.setValueFrameAndPrevFrames(8, "X");
    game.setValueFrameAndPrevFrames(9, "X");
    game.setValueFrameAndPrevFrames(10, "1");
    game.setValueFrameAndPrevFrames(11, "5");
    //THEN
    ASSERT_EQ(30, game.getFrame(0).getValue());
    ASSERT_EQ(30, game.getFrame(1).getValue());
    ASSERT_EQ(30, game.getFrame(2).getValue());
    ASSERT_EQ(30, game.getFrame(3).getValue());
    ASSERT_EQ(30, game.getFrame(4).getValue());
    ASSERT_EQ(30, game.getFrame(5).getValue());
    ASSERT_EQ(30, game.getFrame(6).getValue());
    ASSERT_EQ(30, game.getFrame(7).getValue());
    ASSERT_EQ(21, game.getFrame(8).getValue());
    ASSERT_EQ(16, game.getFrame(9).getValue());
}


TEST_F(GameTests, value_of_all_10_frames_should_be_30)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "X");
    game.setValueFrameAndPrevFrames(1, "X");
    game.setValueFrameAndPrevFrames(2, "X");
    game.setValueFrameAndPrevFrames(3, "X");
    game.setValueFrameAndPrevFrames(4, "X");
    game.setValueFrameAndPrevFrames(5, "X");
    game.setValueFrameAndPrevFrames(6, "X");
    game.setValueFrameAndPrevFrames(7, "X");
    game.setValueFrameAndPrevFrames(8, "X");
    game.setValueFrameAndPrevFrames(9, "X");
    game.setValueFrameAndPrevFrames(10, "X");
    game.setValueFrameAndPrevFrames(11, "X");
    //THEN
    ASSERT_EQ(30, game.getFrame(0).getValue());
    ASSERT_EQ(30, game.getFrame(1).getValue());
    ASSERT_EQ(30, game.getFrame(2).getValue());
    ASSERT_EQ(30, game.getFrame(3).getValue());
    ASSERT_EQ(30, game.getFrame(4).getValue());
    ASSERT_EQ(30, game.getFrame(5).getValue());
    ASSERT_EQ(30, game.getFrame(6).getValue());
    ASSERT_EQ(30, game.getFrame(7).getValue());
    ASSERT_EQ(30, game.getFrame(8).getValue());
    ASSERT_EQ(30, game.getFrame(9).getValue());
}

TEST_F(GameTests, value_of_all_10_frames_should_be_9)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "9-");
    game.setValueFrameAndPrevFrames(1, "9-");
    game.setValueFrameAndPrevFrames(2, "9-");
    game.setValueFrameAndPrevFrames(3, "9-");
    game.setValueFrameAndPrevFrames(4, "9-");
    game.setValueFrameAndPrevFrames(5, "9-");
    game.setValueFrameAndPrevFrames(6, "9-");
    game.setValueFrameAndPrevFrames(7, "9-");
    game.setValueFrameAndPrevFrames(8, "9-");
    game.setValueFrameAndPrevFrames(9, "9-");
    game.setValueFrameAndPrevFrames(10, "0");
    game.setValueFrameAndPrevFrames(11, "0");
    //THEN
    ASSERT_EQ(9, game.getFrame(0).getValue());
    ASSERT_EQ(9, game.getFrame(1).getValue());
    ASSERT_EQ(9, game.getFrame(2).getValue());
    ASSERT_EQ(9, game.getFrame(3).getValue());
    ASSERT_EQ(9, game.getFrame(4).getValue());
    ASSERT_EQ(9, game.getFrame(5).getValue());
    ASSERT_EQ(9, game.getFrame(6).getValue());
    ASSERT_EQ(9, game.getFrame(7).getValue());
    ASSERT_EQ(9, game.getFrame(8).getValue());
    ASSERT_EQ(9, game.getFrame(9).getValue());
}

TEST_F(GameTests, value_of_first_9_frames_should_be_15_frame10_14)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "5/");
    game.setValueFrameAndPrevFrames(1, "5/");
    game.setValueFrameAndPrevFrames(2, "5/");
    game.setValueFrameAndPrevFrames(3, "5/");
    game.setValueFrameAndPrevFrames(4, "5/");
    game.setValueFrameAndPrevFrames(5, "5/");
    game.setValueFrameAndPrevFrames(6, "5/");
    game.setValueFrameAndPrevFrames(7, "5/");
    game.setValueFrameAndPrevFrames(8, "5/");
    game.setValueFrameAndPrevFrames(9, "5/");
    game.setValueFrameAndPrevFrames(10, "4");
    game.setValueFrameAndPrevFrames(11, "0");
    //THEN
    ASSERT_EQ(15, game.getFrame(0).getValue());
    ASSERT_EQ(15, game.getFrame(1).getValue());
    ASSERT_EQ(15, game.getFrame(2).getValue());
    ASSERT_EQ(15, game.getFrame(3).getValue());
    ASSERT_EQ(15, game.getFrame(4).getValue());
    ASSERT_EQ(15, game.getFrame(5).getValue());
    ASSERT_EQ(15, game.getFrame(6).getValue());
    ASSERT_EQ(15, game.getFrame(7).getValue());
    ASSERT_EQ(15, game.getFrame(8).getValue());
    ASSERT_EQ(14, game.getFrame(9).getValue());
}

TEST_F(GameTests, value_of_frames_should_be_f0_20_f1_19_f2_9_f3_18_f4_8_f5_10_f6_6_f7_30_f8_28_f9_19)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "X");
    game.setValueFrameAndPrevFrames(1, "7/");
    game.setValueFrameAndPrevFrames(2, "9-");
    game.setValueFrameAndPrevFrames(3, "X");
    game.setValueFrameAndPrevFrames(4, "-8");
    game.setValueFrameAndPrevFrames(5, "8/");
    game.setValueFrameAndPrevFrames(6, "-6");
    game.setValueFrameAndPrevFrames(7, "X");
    game.setValueFrameAndPrevFrames(8, "X");
    game.setValueFrameAndPrevFrames(9, "X");
    game.setValueFrameAndPrevFrames(10, "8");
    game.setValueFrameAndPrevFrames(11, "1");
    //THEN
    ASSERT_EQ(20, game.getFrame(0).getValue());
    ASSERT_EQ(19, game.getFrame(1).getValue());
    ASSERT_EQ(9, game.getFrame(2).getValue());
    ASSERT_EQ(18, game.getFrame(3).getValue());
    ASSERT_EQ(8, game.getFrame(4).getValue());
    ASSERT_EQ(10, game.getFrame(5).getValue());
    ASSERT_EQ(6, game.getFrame(6).getValue());
    ASSERT_EQ(30, game.getFrame(7).getValue());
    ASSERT_EQ(28, game.getFrame(8).getValue());
    ASSERT_EQ(19, game.getFrame(9).getValue());
}
