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

