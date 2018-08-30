#include <gtest/gtest.h>
#include "Frame.hpp"

struct FrameTests : public ::testing::Test
{
    //GIVEN
    Frame frame;
};

TEST_F(FrameTests, check_if_inicial_value_is_zero)
{
    ASSERT_EQ(0, frame.getValue());
}

TEST_F(FrameTests, set_value_to_five)
{
    //WHEN
    frame.addValue(5);
    //THEN
    ASSERT_EQ(5, frame.getValue());
}

TEST_F(FrameTests, check_if_inicial_isStrike_is_false)
{
    ASSERT_FALSE(frame.isStrike());
}

TEST_F(FrameTests, set_isStrike_to_true)
{
    //WHEN
    frame.setIsStrike();
    //THEN
    ASSERT_TRUE(frame.isStrike());
}

TEST_F(FrameTests, check_if_inicial_isSpare_is_false)
{
    ASSERT_FALSE(frame.isSpare());
}

TEST_F(FrameTests, set_isSpare_to_true)
{
    //WHEN
    frame.setIsSpare();
    //THEN
    ASSERT_TRUE(frame.isSpare());
}
