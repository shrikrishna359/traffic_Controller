#ifndef TRAFFICJUNCTION_HPP
#define TRAFFICJUNCTION_HPP
#include "TrafficPole.h"
#include <gtest/gtest.h>
#include <vector>

enum trafficJunctionResult{
    SUCCESS = 0,
    ERROR_INVALID_NUMBER_OF_POLES = -1,
    ERROR_INVALID_POLE_NUMBER = -2
};
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
    trafficJunctionResult InitalizeTrafficPoles();

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
    trafficJunctionResult AllowTraffic(int PoleNo);

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

    /**
     * @brief Method to get active Pole no
     * @details This method will return m_get_active_pole_no which represents pole is in GO state
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_6}
     * @endcoversreqs
     */
    int get_active_pole_no();

    /**
     * @brief Method to get Total number Pole
     * @details This method will return Total number Pole
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_6}
     * @endcoversreqs
     */
    int getNoOfPole();

    private:
    int mNoOfPole = 0;
    std::vector<std::unique_ptr<TrafficPole>> vct_trafficpole;
    int m_get_active_pole_no = 0;

    FRIEND_TEST(testTrafficJunction, InitalizeTraffic); 
    FRIEND_TEST(testTrafficJunction, AllowTraffic);
    FRIEND_TEST(testTrafficJunction, EnableSlowDown);      
};

#endif  //#ifndef  TRAFFICJUNCTION_HPP