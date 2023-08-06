#include <iostream>
#include <gtest/gtest.h>
#include "TrafficPole.h"
#include <chrono>
#include <thread>

TEST(testTrafficPole,testStop)
{
    TrafficPole tPoleObj;
    EXPECT_EQ(-1, tPoleObj.e_poleState);
    tPoleObj.Stop();
    std::this_thread::sleep_for(std::chrono::milliseconds(1100));
    EXPECT_EQ(0, tPoleObj.e_poleState);
}

TEST(testTrafficPole,testGo)
{
    TrafficPole tPoleObj;
    EXPECT_EQ(-1, tPoleObj.e_poleState);
    tPoleObj.Go();
    std::this_thread::sleep_for(std::chrono::milliseconds(1100));
    EXPECT_EQ(1, tPoleObj.e_poleState);
}

TEST(testTrafficPole,testSlowDown)
{
    TrafficPole tPoleObj;
    EXPECT_EQ(-1, tPoleObj.e_poleState);
    tPoleObj.SlowDown();
    std::this_thread::sleep_for(std::chrono::milliseconds(1100));
    EXPECT_EQ(2, tPoleObj.e_poleState);
}