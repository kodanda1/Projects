#include <pch.h>
#include "gtest/gtest.h"
#include <AnimChannelAngle.h>

TEST(AnimChannelAngleTest, Name)
{
    AnimChannelAngle animchannelangle;

    ASSERT_EQ(L"",animchannelangle.GetName());

    animchannelangle.SetName(L"Harold");

    ASSERT_EQ(L"Harold",animchannelangle.GetName());

}

