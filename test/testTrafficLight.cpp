#include <iostream>
#include "TrafficLight.h"
#include <gtest/gtest.h>

TEST(testTrafficLight,testSwichOn)
{
    TrafficLight tlightObj;
    tlightObj.SwitchOn();
    bool lightState = tlightObj.getLightState();
    EXPECT_EQ(true, lightState);
}

TEST(testTrafficLight,testSwitchOff)
{
    TrafficLight tlightObj;
    tlightObj.SwitchOff();
    bool lightState = tlightObj.getLightState();
    EXPECT_EQ(false, lightState);
}