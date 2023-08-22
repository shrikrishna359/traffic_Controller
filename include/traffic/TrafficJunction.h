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
        
};

#endif  //#ifndef  TRAFFICJUNCTION_HPP