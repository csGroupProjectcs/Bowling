#include <gtest/gtest.h>
#include "Game.hpp"

struct GameConstructorTests: public ::testing::Test
{
    int score;
    const std::string noName {""};
};

TEST_F(GameConstructorTests, NameShouldBeEmptyForDefaultConstructor)
{
    //GIVEN
    Game game;
    //THEN
    ASSERT_EQ(noName, game.getName());
}

TEST_F(GameConstructorTests,  NameShouldBeLeon)
{
    //GIVEN
    Game game("Leon:X|X|X|16");
    const static std::string expectName {"Leon"};
    //THEN
    ASSERT_EQ(expectName, game.getName());
}

TEST_F(GameConstructorTests,  NameShouldBeEmpty)
{
    //GIVEN
    Game game(":X|X|X|16");
    //THEN
    ASSERT_EQ(noName, game.getName());
}

TEST_F(GameConstructorTests,  NameShouldBeEmptyAndScoreShouldBe75)
{
    //GIVEN
    Game game(":X|X|X|16");
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(noName, game.getName());
    ASSERT_EQ(75, score);
}

TEST_F(GameConstructorTests,  NameShouldBeAdamAndScoreShouldBe300)
{
    //GIVEN
    Game game("Adam:X|X|X|X|X|X|X|X|X|X||XX");
    const static std::string expectName {"Adam"};
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(expectName, game.getName());
    ASSERT_EQ(300, score);
}

TEST_F(GameConstructorTests,  NameShouldBeMaxAndScoreShouldBe90)
{
    //GIVEN
    Game game("Max:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||");
    const static std::string expectName {"Max"};
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(expectName, game.getName());
    ASSERT_EQ(90, score);
}

TEST_F(GameConstructorTests,  NameShouldBeEmptyAndScoreShouldBe150)
{
    //GIVEN
    Game game(":5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5");
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(noName, game.getName());
    ASSERT_EQ(150, score);
}

TEST_F(GameConstructorTests,  NameShouldBeEmptyAndScoreShouldBe167)
{
    //GIVEN
    Game game(":X|7/|9-|X|-8|8/|-6|X|X|X||81");
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(noName, game.getName());
    ASSERT_EQ(167, score);
}

TEST_F(GameConstructorTests,  NameShouldBeName1AndScoreShouldBe21)
{
    //GIVEN
    Game game("Name1:X|4-|3");
    const static std::string expectName {"Name1"};
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(expectName, game.getName());
    ASSERT_EQ(21, score);
}

TEST_F(GameConstructorTests,  NameShouldBeName2AndScoreShouldBe17)
{
    //GIVEN
    Game game("Name2:34|X|0-");
    const static std::string expectName {"Name2"};
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(expectName, game.getName());
    ASSERT_EQ(17, score);
}

TEST_F(GameConstructorTests,  NameShouldBeEmptyAndScoreShouldBe24)
{
    //GIVEN
    Game game(":X|22|33");
    //WHEN
    score = game.score();
    //THEN
    ASSERT_EQ(noName, game.getName());
    ASSERT_EQ(24, score);
}
