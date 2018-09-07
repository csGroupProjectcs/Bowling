#include <gtest/gtest.h>
#include "Bowling.hpp"

struct BowlingTests : public ::testing::Test
{
    //GIVEN
    Bowling bowling;
};

TEST_F(BowlingTests, check_if_inicial_NumberOfLanes_is_zero)
{
    //THEN
    ASSERT_EQ(0, bowling.getNumberOfLanes());
}
