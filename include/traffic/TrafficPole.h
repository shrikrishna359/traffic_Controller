#ifndef TRAFFICPOLE_HPP
#define TRAFFICPOLE_HPP
#include "TrafficLight.h"
#include <thread>
#include <gtest/gtest.h>

class TrafficPole
{
    public:
    /**
     * @brief Method to SwitchOn on RedLight
     * @details This method will make Traffic Stop by
     * RedLight on ,Yellow light off and Green Light off
     *
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_5}
     * @req{TRAFFIC_SIGNAL_1}
     * @endcoversreqs
     */    
    void Stop();

    /**
     * @brief Method to SwitchOn on GreenLight
     * @details This method will make Traffic Stop by
     * Green Light on ,Yellow light off and RedLight off
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_5}
     * @req{TRAFFIC_SIGNAL_1} 
     * @endcoversreqs
     */
    void Go();

    /**
     * @brief Method to SwitchOn on YellowLight
     * @details This method will make Traffic SlowDown by
     * Yellow light on ,RedLight light off and Green Light off
     * 
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_5}
     * @req{TRAFFIC_SIGNAL_1} 
     * @endcoversreqs
     */
    void SlowDown();   

    /**
     * @brief Method to blink yellow light
     * @details Threadhandler function for blinking yellow light
     *
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_6}
     * @endcoversreqs
     */   
    void SlowdownThreadHandler();
    
    private:
    TrafficLight obj_Red_Light;
    TrafficLight obj_Yellow_Light;
    TrafficLight obj_Green_Light;

    enum PoleState{
        inValid= -1,
        stop = 0,
        go = 1,
        slowDown = 2
    };
    
   PoleState e_poleState = inValid;
   std::thread mThreadSlowdown;

   FRIEND_TEST(testTrafficPole, testStop);
   FRIEND_TEST(testTrafficPole, testGo);
   FRIEND_TEST(testTrafficPole, testSlowDown);      
};

#endif  //#ifndef  TRAFFICPOLE_HPP