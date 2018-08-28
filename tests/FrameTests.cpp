#include <gtest/gtest.h>
#include "../inc/Frame.hpp"

struct FrameTests : public ::testing::Test
{
    Frame frame;
};

TEST_F(FrameTests, checkIfIncicalValueIsZero)
{
    ASSERT_EQ(0, frame.getValue());
}
