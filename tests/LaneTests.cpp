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

TEST_F(LaneTests, add_1_game_Leon_3spare_5_expect_NumberOfGames_1_name_Leon_score_20)
{
    //WHEN
    Game game("Leon:3/|5");
    line.addGame(game);
    //THEN
    ASSERT_EQ(1, line.getNumberOfGames());
    ASSERT_EQ("Leon", line.getGame(0).getName());
    ASSERT_EQ(20, line.getGame(0).score());
}

TEST_F(LaneTests, add_1_game_and_read_name_game_4_expect_throw)
{
    //WHEN
    Game game("Leon:3/|5");
    line.addGame(game);
    //THEN
    ASSERT_THROW(line.getGame(3).getName(), std::out_of_range);
}
