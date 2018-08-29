#include <gtest/gtest.h>
#include "../inc/Game.hpp"

struct GameTests : public ::testing::Test
{
    //GIVEN
    Game game;
};

TEST_F(GameTests, check_initial_name)
{
    ASSERT_EQ("", game.getName());
}

TEST_F(GameTests, set_name_to_Adam)
{
    //WHEN
    game.setName("Adam");
    //THEN
    ASSERT_EQ("Adam", game.getName());
}

TEST_F(GameTests, initial_score_shoud_be_zero)
{
    ASSERT_EQ(0, game.score());
}

TEST_F(GameTests, score_should_be_ten_strike)
{
    //WHEN
    game.checkValue("X ");
    //THEN
    ASSERT_EQ(10, game.checkValue("X "));
}

TEST_F(GameTests, score_should_be_ten_spare)
{
    //WHEN
    game.checkValue("2/");
    //THEN
    ASSERT_EQ(10, game.checkValue("2/"));
}

TEST_F(GameTests, score_should_be_nine)
{
    //WHEN
    game.checkValue("45");
    //THEN
    ASSERT_EQ(9, game.checkValue("45"));
}
