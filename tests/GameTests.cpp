#include <gtest/gtest.h>
#include "../inc/Game.hpp"

struct GameTests : public ::testing::Test
{
    Game game;
};

TEST_F(GameTests, check_if_zero_eq_one)
{
    ASSERT_EQ(0, 1);
}

