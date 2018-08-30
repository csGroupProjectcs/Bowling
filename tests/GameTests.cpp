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
