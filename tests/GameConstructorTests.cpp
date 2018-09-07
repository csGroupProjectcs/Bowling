#include <gtest/gtest.h>
#include "Game.hpp"

struct GameConstructorTests: public ::testing::Test
{
};

TEST_F(GameConstructorTests, NameShouldBeEmptyForDefaultConstructor)
{
    //GIVEN
    Game game;
    //THEN
    ASSERT_EQ("", game.getName());
}

TEST_F(GameConstructorTests,  NameShouldBeLeon)
{
    //GIVEN
    Game game("Leon:|X|X|X|16");
    //THEN
    ASSERT_EQ("Leon", game.getName());
}
