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
