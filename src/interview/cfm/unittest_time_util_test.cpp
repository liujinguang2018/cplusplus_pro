#include "time_util.h"

#include <gtest/gtest.h>

TEST(minutes_to_time_displayed, HandlerTrueReturn)
{
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(0), "00:00AM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(5), "00:05AM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(60 + 3), "01:03AM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(60 * 8 + 30), "08:30AM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(60 * 10 + 9), "10:09AM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(60 * 12 + 6), "12:06PM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(60 * 13 + 8), "01:08PM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(60 * 14 + 39), "02:39PM");
    EXPECT_EQ(TimeUtil::minutes_to_time_displayed(60 * 23 + 1), "11:01PM");
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}