#include <gtest/gtest.h>
#include "Game.hpp"

struct GameConstructorTests: public ::testing::Test
{
    int score;
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

TEST_F(GameConstructorTests,  NameShouldBeEmpty)
{
    //GIVEN
    Game game(":|X|X|X|16");
    //THEN
    ASSERT_EQ("", game.getName());
}

TEST_F(GameConstructorTests,  NameShouldBeEmptyAndScoreShouldBe75)
{
    //GIVEN
    Game game(":|X|X|X|16");
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ("", game.getName());
    ASSERT_EQ(75, score);
}
