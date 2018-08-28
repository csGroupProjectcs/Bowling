#include <gtest/gtest.h>
#include "../inc/Frame.hpp"

struct FrameTests : public ::testing::Test
{
    Frame frame;
};

TEST_F(FrameTests, check_if_incical_value_is_zero)
{
    ASSERT_EQ(0, frame.getValue());
}

TEST_F(FrameTests, check_set_value_to_five)
{
    frame.setValue(5);
    ASSERT_EQ(5, frame.getValue());
}

TEST_F(FrameTests, check_if_incical_isStrike_is_false)
{
    ASSERT_FALSE(frame.isStrike());
}
