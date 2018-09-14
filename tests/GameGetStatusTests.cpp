#include <gtest/gtest.h>
#include "Game.hpp"

struct GetStatusGameTests : public ::testing::Test
{
    std::string status;
};

TEST_F (GetStatusGameTests, GivenUnfinishedGameWithCompleteFrameAtEndShouldHaveStatusGameInProgress)
{
    //GIVEN
    Game game(":12|21|42");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game in progress", status);
}

TEST_F (GetStatusGameTests, GivenUnfinishedGameWithIncompleteFrameAtEndShouldHaveStatusGameInProgress)
{
    //GIVEN
    Game game(":12|21|4");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game in progress", status);
}

TEST_F (GetStatusGameTests, GivenUnfinishedGameWith10IncompleteFrameAtEndShouldHaveStatusGameInProgress)
{
    //GIVEN
    Game game(":12|21|4/|12|X|41|11|-4|--|3");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game in progress", status);
}

TEST_F (GetStatusGameTests, GivenFinishedGameShouldHaveStatusGameFinished)
{
    //GIVEN
    Game game(":12|21|4/|12|X|41|11|-4|--|32||");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game finished", status);
}

TEST_F (GetStatusGameTests, GivenUnfinishedGameWithSpareIn10FrameShouldHaveStatusGameInProgress)
{
    //GIVEN
    Game game(":12|21|4/|12|X|41|11|-4|--|3/||");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game in progress", status);
}

TEST_F (GetStatusGameTests, GivenUnfinishedGameWithStrikeIn10FrameAnd0BonusBallsShouldHaveStatusGameInProgress)
{
    //GIVEN
    Game game(":12|21|4/|12|X|41|11|-4|--|X||");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game in progress", status);
}

TEST_F (GetStatusGameTests, GivenUnfinishedGameWithStrikeIn10FrameAnd1BonusBallsShouldHaveStatusGameInProgress)
{
    //GIVEN
    Game game(":12|21|4/|12|X|41|11|-4|--|X||5");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game in progress", status);
}

TEST_F (GetStatusGameTests, GivenFinishedGameWithStrikeIn10FrameShouldHaveStatusGameFinished)
{
    //GIVEN
    Game game(":12|21|4/|12|X|41|11|-4|--|X||52");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game finished", status);
}

TEST_F (GetStatusGameTests, GivenFinishedGameWithSpareIn10FrameShouldHaveStatusGameFinished)
{
    //GIVEN
    Game game(":12|21|4/|12|X|41|11|-4|--|6/||X");
    //WHEN
    status = game.getStatusGame();
    //THEN
    ASSERT_EQ("game finished", status);
}
