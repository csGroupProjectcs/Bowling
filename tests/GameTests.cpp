#include <gtest/gtest.h>
#include "Game.hpp"

struct GameTests : public ::testing::Test
{
    int firstBall, secondBall, score;
    Game game;
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

