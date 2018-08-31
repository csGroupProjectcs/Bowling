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
