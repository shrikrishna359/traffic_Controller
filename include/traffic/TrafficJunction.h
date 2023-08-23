#ifndef TRAFFICJUNCTION_HPP
#define TRAFFICJUNCTION_HPP
#include "TrafficPole.h"
#include <gtest/gtest.h>
#include <vector>

class TrafficJunction
{
    public:
        
        TrafficJunction(int noOfPole):mNoOfPole(noOfPole)
        {
            InitalizeTrafficPoles();
        }

    /**
     * @brief Method to Initalize TrafficPoles based on number of pole
     * @details This method Create unique pointer for Traffic pole class and
     * store mNoOfPole number of unique pointer in vct_trafficpole vector
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_3}
     * @req{TRAFFIC_SIGNAL_1} 
     * @endcoversreqs
     */
    void InitalizeTrafficPoles();

    /**
     * @brief Method to allow Traffic for selected Pole
     * @details This method will turning off all pole except selected pole
     * and turning on Green light for selected Pole
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_3}
     * @req{TRAFFIC_SIGNAL_1} 
     * @endcoversreqs
     */
    void AllowTraffic(int PoleNo);

    /**
     * @brief Method to disable all traffic Poles
     * @details This method will turning off all poles
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_3}
     * @req{TRAFFIC_SIGNAL_1} 
     * @endcoversreqs
     */
    void DisableTraffic();

    /**
     * @brief Method to Enable blinking yellow light
     * @details This method will call Slowdown such that all pole should blink yellow light
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_6}
     * @endcoversreqs
     */
    void EnableSlowDown();

    private:
    int mNoOfPole;
    std::vector<std::unique_ptr<TrafficPole>> vct_trafficpole;

    FRIEND_TEST(testTrafficJunction, InitalizeTraffic); 
    FRIEND_TEST(testTrafficJunction, AllowTraffic);
    FRIEND_TEST(testTrafficJunction, EnableSlowDown);      
};

#endif  //#ifndef  TRAFFICJUNCTION_HPP