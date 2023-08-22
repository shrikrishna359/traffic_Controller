#ifndef TRAFFICJUNCTION_HPP
#define TRAFFICJUNCTION_HPP
#include "TrafficPole.h"
#include <gtest/gtest.h>
#include <vector>
#include <iostream>
class TrafficJunction
{
    public:
        
        TrafficJunction(int noOfPole):mNoOfPole(noOfPole)
        {
            InitalizeTrafficPoles();
        }

        void InitalizeTrafficPoles();

        void AllowTraffic(int PoleNo);

        void DisableTraffic();

        void EnableSlowDown();

    private:
        int mNoOfPole;
        std::vector<std::unique_ptr<TrafficPole>> vct_trafficpole;

    FRIEND_TEST(testTrafficJunction, InitalizeTraffic); 
    FRIEND_TEST(testTrafficJunction, AllowTraffic);
    FRIEND_TEST(testTrafficJunction, EnableSlowDown);      
};

#endif  //#ifndef  TRAFFICJUNCTION_HPP