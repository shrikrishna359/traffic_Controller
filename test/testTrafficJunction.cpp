#include <iostream>
#include <gtest/gtest.h>
#include "TrafficJunction.h"
#include <chrono>
#include <thread>

TEST(testTrafficJunction,InitalizeTraffic)
{
    TrafficJunction tJuncObj(2);
    tJuncObj.InitalizeTrafficPoles();
    EXPECT_EQ(2, tJuncObj.mNoOfPole);
}

TEST(testTrafficJunction,AllowTraffic)
{
    TrafficJunction tJuncObj(3);
    tJuncObj.AllowTraffic(3);
    tJuncObj.AllowTraffic(2);
    tJuncObj.AllowTraffic(1);
    tJuncObj.AllowTraffic(4);
    EXPECT_EQ(3, tJuncObj.mNoOfPole);
}

TEST(testTrafficJunction,EnableSlowDown)
{
    TrafficJunction tJuncObj(2);
    tJuncObj.DisableTraffic();
    tJuncObj.EnableSlowDown();
    EXPECT_EQ(2, tJuncObj.mNoOfPole);
}
