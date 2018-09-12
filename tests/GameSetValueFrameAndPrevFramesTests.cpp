#include <gtest/gtest.h>
#include "Game.hpp"
#include <vector>

struct GameTests : public ::testing::Test
{
    int firstBall, secondBall, score;
    Game game;

    void fillSetValueFrameAndPrevFrames (std::vector<std::string> frameScore)
    {
        for (int i = 0; i < frameScore.size() && i < 12; i++)
        {
            game.setValueFrameAndPrevFrames(i, frameScore[i]);
        }
    }

    void fillASSERT_EQ (std::vector<int> expectedValues)
    {
        for (int i = 0; i < expectedValues.size(); i++)
        {
            ASSERT_EQ(expectedValues[i], game.getFrame(i).getValue());
        }
    }
};

TEST_F(GameTests, GivenFrameFiveWithZeroShouldHaveValue5)
{
    //WHEN
    game.setValueFrameAndPrevFrames(3, "5-");
    //THEN
    ASSERT_EQ(5, game.getFrame(3).getValue());
}

TEST_F(GameTests, GivenFrameFourWithZeroShouldHaveValue4)
{
    //GIVEN
    std::vector<int> expectedValuesFor4And0={4};
    //WHEN
    game.setValueFrameAndPrevFrames(0, "4-");
    //THEN
    fillASSERT_EQ(expectedValuesFor4And0);
}
TEST_F(GameTests, GivenFrameTwoWithSpareAnd51ShouldHaveValues15And6)
{
    //GIVEN
    std::vector<std::string> one2WithSpareAndOne51 = {"2/", "51"};
    std::vector<int> expectedValuesForOne2WithSpareAndOne51={15, 6};
    //WHEN
    fillSetValueFrameAndPrevFrames(one2WithSpareAndOne51);
    //THEN
    fillASSERT_EQ (expectedValuesForOne2WithSpareAndOne51);
}

TEST_F(GameTests, GivenThreeFramesWithStrikeShouldHaveValues30And20And10)
{
    //GIVEN
    std::vector<std::string> threeStrikeFrames = {"X", "X", "X"};
    std::vector<int> expectedValuesForthreeStrikeFrames = {30, 20, 10};
    //WHEN
    fillSetValueFrameAndPrevFrames(threeStrikeFrames);
    //THEN
    fillASSERT_EQ (expectedValuesForthreeStrikeFrames);
}

TEST_F(GameTests, GivenFrameStrikeAndZeroWithSpareAndStrikeShouldHaveValues20And20And10)
{
    //GIVEN
    std::vector<std::string> frameStrikeAndZeroWithSpareAndStrike = {"X", "-/", "X"};
    std::vector<int> expectedValuesForFrameStrikeAndZeroWithSpareAndStrike = {20, 20, 10};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameStrikeAndZeroWithSpareAndStrike);
    //THEN
    fillASSERT_EQ (expectedValuesForFrameStrikeAndZeroWithSpareAndStrike);
}

TEST_F(GameTests, GivenFrameStrikeAndSixWithSpareAndTwoZerosShouldHaveValues20and10And0)
{
    //GIVEN
    std::vector<std::string> frameStrikeAndSixWithSpareAndTwoZeros = {"X", "6/", "--"};
    std::vector<int> expectedValuesForFrameStrikeAndSixWithSpareAndTwoZeros = {20, 10, 0};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameStrikeAndSixWithSpareAndTwoZeros);
    //THEN
    fillASSERT_EQ (expectedValuesForFrameStrikeAndSixWithSpareAndTwoZeros);
}

TEST_F(GameTests, GivenFrameStrikeAnd34ShouldHaveValues17and7)
{
    //GIVEN
    std::vector<std::string> frameStrikeAnd34ShouldHaveValues17and7 = {"X", "34"};
    std::vector<int> expectedValuesForFrameStrikeAnd34ShouldHaveValues17and7 = {17, 7};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameStrikeAnd34ShouldHaveValues17and7);
    //THEN
    fillASSERT_EQ (expectedValuesForFrameStrikeAnd34ShouldHaveValues17and7);
}

TEST_F(GameTests, GivenFrame34AndIncompleteFrame4ShouldHaveValues7And4)
{
    //GIVEN
    std::vector<std::string> frame34AndIncompleteFrame4ShouldHaveValues7And4 = {"34", "4"};
    std::vector<int> expectedValuesForFrame34AndIncompleteFrame4ShouldHaveValues7And4 = {7, 4};
    //WHEN
    fillSetValueFrameAndPrevFrames(frame34AndIncompleteFrame4ShouldHaveValues7And4);
    //THEN
    fillASSERT_EQ (expectedValuesForFrame34AndIncompleteFrame4ShouldHaveValues7And4);
}

TEST_F(GameTests, GivenTenFramesWitchStrikeAndOneAndFiveInBonusBallsShouldHaveValueEqual_30_InFirstEightFrames_21_AtNineFrameAnd_16_InTenFrame)
{
    //GIVEN
    std::vector<std::string> frameTenStrikeAndOneAndFiveInBonusBalls = {
        "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "1", "5"};
    std::vector<int> expectedValuesForFrameTenStrikeAndOneAndFiveInBonusBalls = {
        30, 30, 30, 30, 30, 30, 30, 30, 21, 16};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenStrikeAndOneAndFiveInBonusBalls);
    //THEN
    fillASSERT_EQ (expectedValuesForFrameTenStrikeAndOneAndFiveInBonusBalls);
}

TEST_F(GameTests, GivenTenFramesWitchStrikeAndStrikeInBothBonusBallsShouldHaveValueEqual_30_InAllTenFrames)
{
    //GIVEN
    std::vector<std::string> frameTenStrikeAndStrikeInBothBonusBalls = {
        "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X"};
    std::vector<int> expectedValuesForFrameTenStrikeAndStrikeInBothBonusBalls = {
        30, 30, 30, 30, 30, 30, 30, 30, 30, 30};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenStrikeAndStrikeInBothBonusBalls);
    //THEN
    fillASSERT_EQ (expectedValuesForFrameTenStrikeAndStrikeInBothBonusBalls);
}

TEST_F(GameTests, GivenTenFramesWitchBallsNineAndZeroShouldHaveValuesNineInFirstTenFrames)
{
    //GIVEN
    std::vector<std::string> frameTenBallsNineAndZero = {
        "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "0", "0"};
    std::vector<int> expectedValuesForFrameTenBallsNineAndZero = {
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenBallsNineAndZero);
    //THEN
    fillASSERT_EQ (expectedValuesForFrameTenBallsNineAndZero);
}

TEST_F(GameTests, GivenTenFramesWithFiveAndSpareAndFourInBonusBallShouldHaveValuesInFirstNineFramesEqual15AndInLast14)
{
    //GIVEN
    std::vector<std::string> frameTenFiveAndSpareAndFourInBonusBall = {
        "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "4", "0"};
    std::vector<int> expectedValuesForFrameTenFiveAndSpareAndFourInBonusBall = {
        15, 15, 15, 15, 15, 15, 15, 15, 15, 14};
    //WHEN
    fillSetValueFrameAndPrevFrames(frameTenFiveAndSpareAndFourInBonusBall);
    //THEN
    fillASSERT_EQ (expectedValuesForFrameTenFiveAndSpareAndFourInBonusBall);
}

TEST_F(GameTests, GivenFramesShouldHaveFollowingValues_20_19_9_18_8_10_6_30_28_19)
{
    //GIVEN
    std::vector<std::string> framesWithRandomValue = {
        "X", "7/", "9-", "X", "-8", "8/", "-6", "X", "X", "X", "8", "1"};
    std::vector<int> expectedValuesForFramesWithRandomValue= {
        20, 19, 9, 18, 8, 10, 6, 30, 28, 19};
    //WHEN
    fillSetValueFrameAndPrevFrames(framesWithRandomValue);
    //THEN
    fillASSERT_EQ (expectedValuesForFramesWithRandomValue);
}
