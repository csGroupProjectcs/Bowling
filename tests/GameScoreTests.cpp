#include <gtest/gtest.h>
#include "Game.hpp"

struct GameScoreTests : public ::testing::Test
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
};

TEST_F(GameScoreTests, GivenTenFramesWitchStrikeAndStrikeInBothBonusBallsShouldHaveScoreValueEqual_300)
{
    //GIVEN
    std::vector<std::string> tenStrikeAndTwoStrikeBonusValue = {
        "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X"};
    //WHEN
    fillSetValueFrameAndPrevFrames(tenStrikeAndTwoStrikeBonusValue);
    //THEN
    ASSERT_EQ(300, game.score());
}

TEST_F(GameScoreTests, GivenTenFramesWitchStrikeAndOneAndFiveInBonusBallsShouldHaveScoreValueEqual_277)
{
    //GIVEN
    std::vector<std::string> tenStrikeAnd1And5BonusValue = {
        "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "1", "5"};
    //WHEN
    fillSetValueFrameAndPrevFrames(tenStrikeAnd1And5BonusValue);
    //THEN
    ASSERT_EQ(277, game.score());
}

TEST_F(GameScoreTests, GivenTenFramesWitchBallsNineAndZeroShouldHaveScoreValueEqual_90)
{
    //GIVEN
    std::vector<std::string> ten9And0BonusValue = {
        "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "9-", "0", "0"};
    //WHEN
    fillSetValueFrameAndPrevFrames(ten9And0BonusValue);
    //THEN
    ASSERT_EQ(90, game.score());
}

TEST_F(GameScoreTests, GivenTenFramesWithFiveAndSpareAndFourInBonusBallShouldHaveScoreValueEqual_149)
{
    //GIVEN
    std::vector<std::string> ten5And4BonusValue = {
        "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "5/", "4", "0"};
    //WHEN
    fillSetValueFrameAndPrevFrames(ten5And4BonusValue);
    //THEN
    ASSERT_EQ(149, game.score());
}

TEST_F(GameScoreTests, GivenTenRandomFramesShouldHaveScoreValueEqual_167)
{
    //GIVEN
    std::vector<std::string> randomValue = {
        "X", "7/", "9-", "X", "-8", "8/", "-6", "X", "X", "X", "8", "1"};
    //WHEN
    fillSetValueFrameAndPrevFrames(randomValue);
    //THEN
    ASSERT_EQ(167, game.score());
}
