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
    game.setIsStrikeOrSpare(1, "5/");
    game.setIsStrikeOrSpare(2, "X");
    game.setIsStrikeOrSpare(5, "/");
    //THEN
    ASSERT_TRUE(game.frame_[2].isStrike());
    ASSERT_TRUE(game.frame_[1].isSpare());
    ASSERT_TRUE(game.frame_[5].isSpare());
}