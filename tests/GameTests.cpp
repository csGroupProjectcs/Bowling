#include <gtest/gtest.h>
#include "../inc/Game.hpp"

struct GameTests : public ::testing::Test
{
    Game game;
};

TEST_F(GameTests, check_initial_name)
{
    ASSERT_EQ("", game.getName());
}

