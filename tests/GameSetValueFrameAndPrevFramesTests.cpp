#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "Game.hpp"
#include <vector>

struct GameSetValueFrameAndPrevFramesTests : public ::testing::Test
{
    int firstBall, secondBall, score;
    Game game;

    void fillSetValueFrameAndPrevFrames (std::vector<std::string> frameScore)
    {
        for (unsigned int i = 0; i < frameScore.size() && i < 12; i++)
        {
            game.setValueFrameAndPrevFrames(i, frameScore[i]);
        }
    }

    std::vector<int> fillframesValue()
    {
        std::vector<int> frameValue (10);
        for (unsigned int i = 0; i < 10; i++)
        {
            frameValue [i]= game.getFrame(i).getValue();
        }
        return frameValue;
    }
};

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenFrameFiveWithZeroShouldHaveValue5)
{
    //WHEN
    game.setValueFrameAndPrevFrames(3, "5-");
    //THEN
    ASSERT_EQ(5, game.getFrame(3).getValue());
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenFrameTwoWithSpareAnd51ShouldHaveValues15And6)
{
    //GIVEN
    std::vector<std::string> one2WithSpareAndOne51 = {"2/", "51"};
    //WHEN
    fillSetValueFrameAndPrevFrames(one2WithSpareAndOne51);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(15, 6, 0, 0, 0, 0, 0, 0, 0, 0));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenThreeFramesWithStrikeShouldHaveValues30And20And10)
{
    //GIVEN
    std::vector<std::string> threeStrikeFrames = {"X", "X", "X"};
    //WHEN
    fillSetValueFrameAndPrevFrames(threeStrikeFrames);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(30, 20, 10, 0, 0, 0, 0, 0, 0, 0));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenFrameStrikeAndZeroWithSpareAndStrikeShouldHaveValues20And20And10)
{
    //GIVEN
    std::vector<std::string> frameStrikeAndZeroWithSpareAndStrike = {"X", "-/", "X"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameStrikeAndZeroWithSpareAndStrike);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(20, 20, 10, 0, 0, 0, 0, 0, 0, 0));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenFrameStrikeAndSixWithSpareAndTwoZerosShouldHaveValues20and10And0)
{
    //GIVEN
    std::vector<std::string> frameStrikeAndSixWithSpareAndTwoZeros = {"X", "6/", "--"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameStrikeAndSixWithSpareAndTwoZeros);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(20, 10, 0, 0, 0, 0, 0, 0, 0, 0));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenFrameStrikeAnd34ShouldHaveValues17and7)
{
    //GIVEN
    std::vector<std::string> frameStrikeAnd34ShouldHaveValues17and7 = {"X", "34"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameStrikeAnd34ShouldHaveValues17and7);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(17, 7, 0, 0, 0, 0, 0, 0, 0, 0));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenFrame34AndIncompleteFrame4ShouldHaveValues7And4)
{
    //GIVEN
    std::vector<std::string> frame34AndIncompleteFrame4ShouldHaveValues7And4 = {"34", "4"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frame34AndIncompleteFrame4ShouldHaveValues7And4);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(7, 4, 0, 0, 0, 0, 0, 0, 0, 0));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenTenFramesWitchStrikeAndOneAndFiveInBonusBallsShouldHaveValueEqual_30_InFirstEightFrames_21_AtNineFrameAnd_16_InTenFrame)
{
    //GIVEN
    std::vector<std::string> frameTenStrikeAndOneAndFiveInBonusBalls = {
        "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "1", "5"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenStrikeAndOneAndFiveInBonusBalls);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(30, 30, 30, 30, 30, 30, 30, 30, 21, 16));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenTenFramesWitchStrikeAndStrikeInBothBonusBallsShouldHaveValueEqual_30_InAllTenFrames)
{
    //GIVEN
    std::vector<std::string> frameTenStrikeAndStrikeInBothBonusBalls = {
        "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenStrikeAndStrikeInBothBonusBalls);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(30, 30, 30, 30, 30, 30, 30, 30, 30, 30));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenTenFramesWitchBallsNineAndZeroShouldHaveValuesNineInFirstTenFrames)
{
    //GIVEN
    std::vector<std::string> frameTenBallsNineAndZero = {
        "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "0", "0"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenBallsNineAndZero);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(9, 9, 9, 9, 9, 9, 9, 9, 9, 9));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenTenFramesWithFiveAndSpareAndFourInBonusBallShouldHaveValuesInFirstNineFramesEqual15AndInLast14)
{
    //GIVEN
    std::vector<std::string> frameTenFiveAndSpareAndFourInBonusBall = {
        "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "4", "0"};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenFiveAndSpareAndFourInBonusBall);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(15, 15, 15, 15, 15, 15, 15, 15, 15, 14));
}

TEST_F(GameSetValueFrameAndPrevFramesTests, GivenFramesShouldHaveFollowingValues_20_19_9_18_8_10_6_30_28_19)
{
    //GIVEN
    std::vector<std::string> framesWithRandomValue = {
        "X", "7/", "9-", "X", "-8", "8/", "-6", "X", "X", "X", "8", "1"};
    //WHEN
    fillSetValueFrameAndPrevFrames(framesWithRandomValue);
    //THEN
    ASSERT_THAT (fillframesValue(), testing::ElementsAre(20, 19, 9, 18, 8, 10, 6, 30, 28, 19));
}

