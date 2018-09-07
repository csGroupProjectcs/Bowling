#include <gtest/gtest.h>
#include "Lane.hpp"

struct LaneTests : public ::testing::Test
{
    //GIVEN
    Lane line;
};

TEST_F(LaneTests, check_if_inicial_NumberOfGames_is_zero)
{
    //THEN
    ASSERT_EQ(0, line.getNumberOfGames());
}

TEST_F(LaneTests, add_1_game_expect_NumberOfGames_1_and_name_Leon)
{
    //WHEN
    Game game1("Leon");
    line.addGame(game1);
    //THEN
    ASSERT_EQ(1, line.getNumberOfGames());
    ASSERT_EQ("Leon", line.getGame(0).getName());
}
