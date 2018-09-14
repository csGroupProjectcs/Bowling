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

TEST_F(LaneTests, adding_a_game_in_progress)
{
    //WHEN
    Game game("Boniek:12|X");
    Lane lane;
    lane.addGame(game);
    //THEN
    ASSERT_EQ("game in progress", lane.getStatusLane());
}

TEST_F(LaneTests, adding_a_finished_game)
{
    //WHEN
    Game game("Boniek:12|X|2/|31|45|X|12|12|12|11");
    Lane lane;
    lane.addGame(game);
    //THEN
    ASSERT_EQ("game finished", lane.getStatusLane());
}

TEST_F(LaneTests, no_game)
{
    //WHEN
    Lane lane;
    //THEN
    ASSERT_EQ("no game", lane.getStatusLane());
}

TEST_F(LaneTests, GivenGamesInLaneSholudHaveSttatusInProgress)
{
    //WHEN
    Game game1("Boniek:12|X|2/|31|45|X|12|12|12|11");
    Game game2("Max:12|X|2/|31|45|X|12|12|12|11");
    Game game3("Bon:12|X|2/|31|45|X|12|12|12|11");
    Game game4("A:12|X|2/|31|45|X|12|12|12|1/||");
    Lane lane;
    lane.addGame(game1);
    lane.addGame(game2);
    lane.addGame(game3);
    lane.addGame(game4);
    //THEN
    ASSERT_EQ("game in progress", lane.getStatusLane());
}
