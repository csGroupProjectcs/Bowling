#include <gtest/gtest.h>

struct BowlingTests : public ::testing::Test
{
};

TEST_F(BowlingTests, assertThatFalseIsTrue)
{
    ASSERT_TRUE(true);
}
