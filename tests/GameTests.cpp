#include <gtest/gtest.h>
#include "Game.hpp"

struct GameTests : public ::testing::Test
{
    int firstBall, secondBall, score;
    Game game;
    void FillSetValueFrameAndPrevFrames(std::string frameScore[12])
    {
        for (int i=0; i<12; i++)
        {
            game.setValueFrameAndPrevFrames(i, frameScore[i]);
        }
    }
};

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
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("X");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(10, score);
}

TEST_F(GameTests, score_should_be_ten_spare)
{
    //GIVEN
    Game game;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("2/");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(10, score);
}

TEST_F(GameTests, score_should_be_nine)
{
    //GIVEN
    Game game;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("45");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(9, score);
}

TEST_F(GameTests, score_should_be_seven)
{
    //GIVEN
    Game game;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("-7");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(7, score);
}

TEST_F(GameTests, score_should_be_three)
{
    //GIVEN
    Game game;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("3-");
    score = firstBall + secondBall;
    //THEN
    ASSERT_EQ(3, score);
}

TEST_F(GameTests, GivenValue34ConvertValueToPairOfIntsShouldReturn3And4)
{
    //GIVEN
    Game game;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("34");
    //THEN
    ASSERT_EQ(3, firstBall);
    ASSERT_EQ(4, secondBall);
}

TEST_F(GameTests, GivenValueStrikeConvertValueToPairOfIntsShouldReturn10And0)
{
    //GIVEN
    Game game;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("X");
    //THEN
    ASSERT_EQ(10, firstBall);
    ASSERT_EQ(0, secondBall);
}

TEST_F(GameTests, GivenValueZeroWithSpareConvertValuesToPairOfIntsShouldReturn0And10)
{
    //GIVEN
    Game game;
    //WHEN
    std::tie(firstBall, secondBall) = game.convertValueToPairOfInts("-/");
    //THEN
    ASSERT_EQ(0, firstBall);
    ASSERT_EQ(10, secondBall);
}

TEST_F(GameTests, GivenFrameFiveWithZeroShouldHaveValue5)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(3, "5-");
    //THEN
    ASSERT_EQ(5, game.getFrame(3).getValue());
}

TEST_F(GameTests, GivenFrameTwoWithSpareAnd51ShouldHaveValues15And6)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "2/");
    game.setValueFrameAndPrevFrames(1, "51");
    //THEN
    ASSERT_EQ(15, game.getFrame(0).getValue());
    ASSERT_EQ(6, game.getFrame(1).getValue());
}

TEST_F(GameTests, GivenThreeFramesWithStrikeShouldHaveValues30And20And10)
{
    //GIVEN
    Game game;
    //WHEN
    game.setValueFrameAndPrevFrames(0, "X");
    game.setValueFrameAndPrevFrames(1, "X");
    game.setValueFrameAndPrevFrames(2, "X");
    //THEN
    ASSERT_EQ(30, game.getFrame(0).getValue());
    ASSERT_EQ(20, game.getFrame(1).getValue());
    ASSERT_EQ(10, game.getFrame(2).getValue());
}

TEST_F(GameTests, GivenFrameStrikeAndZeroWithSpareAndStrikeShouldHaveValues20And20And10)
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
    ASSERT_EQ(10, game.getFrame(2).getValue());
}

TEST_F(GameTests, GivenFrameStrikeAndSixWithSpareAndTwoZerosShouldHaveValues20and10And0)
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
    ASSERT_EQ(0, game.getFrame(3).getValue());
}

TEST_F(GameTests, GivenFrameStrikeAnd34ShouldHaveValues17and7)
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

TEST_F(GameTests, GivenFrame34AndIncompleteFrame4ShouldHaveValues7And4)
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

TEST_F(GameTests, GivenTenFramesWitchStrikeAndOneAndFiveInBonusBallsShouldHaveValueEqual_30_InFirstEightFrames_21_AtNineFrameAnd_16_InTenFrame)
{
    //GIVEN
    std::string tenStrikeAnd1And5BonusValue[] = {"X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "1", "5"};
    //WHEN
    FillSetValueFrameAndPrevFrames(tenStrikeAnd1And5BonusValue);
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


TEST_F(GameTests, GivenTenFramesWitchStrikeAndStrikeInBothBonusBallsShouldHaveValueEqual_30_InAllTenFrames)
{
    //GIVEN
    std::string tenStrikeAndTwoStrikeBonusValue[] = {"X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X"};
    //WHEN
    FillSetValueFrameAndPrevFrames(tenStrikeAndTwoStrikeBonusValue);
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

TEST_F(GameTests, GivenTenFramesWitchBallsNineAndZeroShouldHaveValuesNineInFirstTenFrames)
{
    //GIVEN
    std::string ten9And0BonusValue[] = {"9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "0", "0"};
    //WHEN
    FillSetValueFrameAndPrevFrames(ten9And0BonusValue);
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

TEST_F(GameTests, GivenTenFramesWithFiveAndSpareAndFourInBonusBallShouldHaveValuesInFirstNineFramesEqual15AndInLast14)
{
    //GIVEN
    std::string ten5And4BonusValue[] = {"5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "4", "0"};
    //WHEN
    FillSetValueFrameAndPrevFrames(ten5And4BonusValue);
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

TEST_F(GameTests, GivenFramesShouldHaveFollowingValues_20_19_9_18_8_10_6_30_28_19)
{
    //GIVEN
    std::string randomValue[] = {"X", "7/", "9-", "X", "-8", "8/", "-6", "X", "X", "X", "8", "1"};
    //WHEN
    FillSetValueFrameAndPrevFrames(randomValue);
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
TEST_F(GameTests, GivenTenFramesWitchStrikeAndStrikeInBothBonusBallsShouldHaveScoreValueEqual_300)
{
    //GIVEN
    std::string tenStrikeAndTwoStrikeBonusValue[] = {"X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X"};
    //WHEN
    FillSetValueFrameAndPrevFrames(tenStrikeAndTwoStrikeBonusValue);
    //THEN
    ASSERT_EQ(300, game.score());
}
TEST_F(GameTests, GivenTenFramesWitchStrikeAndOneAndFiveInBonusBallsShouldHaveScoreValueEqual_277)
{
    //GIVEN
    std::string tenStrikeAnd1And5BonusValue[] = {"X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "1", "5"};
    //WHEN
    FillSetValueFrameAndPrevFrames(tenStrikeAnd1And5BonusValue);
    //THEN
    ASSERT_EQ(277, game.score());
}
TEST_F(GameTests, GivenTenFramesWitchBallsNineAndZeroShouldHaveScoreValueEqual_90)
{
    //GIVEN
    std::string ten9And0BonusValue[] = {"9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "0", "0"};
    //WHEN
    FillSetValueFrameAndPrevFrames(ten9And0BonusValue);
    //THEN
    ASSERT_EQ(90, game.score());
}
TEST_F(GameTests, GivenTenFramesWithFiveAndSpareAndFourInBonusBallShouldHaveScoreValueEqual_149)
{
    //GIVEN
    std::string ten5And4BonusValue[] = {"5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "4", "0"};
    //WHEN  
    FillSetValueFrameAndPrevFrames(ten5And4BonusValue);
    //THEN
    ASSERT_EQ(149, game.score());
}
TEST_F(GameTests, GivenTenRandomFramesShouldHaveScoreValueEqual_167)
{
    //GIVEN
    std::string randomValue[] = {"X", "7/", "9-", "X", "-8", "8/", "-6", "X", "X", "X", "8", "1"};
    //WHEN
    FillSetValueFrameAndPrevFrames(randomValue);
    //THEN
    ASSERT_EQ(167, game.score());
}
