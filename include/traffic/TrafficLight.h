#ifndef TRAFFILIGHT_HPP
#define TRAFFILIGHT_HPP

class TrafficLight
{
    public:
    /**
     * @brief Method to SwitchOn on TrafficLight
     * @details This method will make lightState Variable to true
     *
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_5}
     * @endcoversreqs
     */    
    void SwitchOn();

    /**
     * @brief Method to SwitchOff on TrafficLight
     * @details This method will make lightState Variable to False
     *
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_5}
     * @endcoversreqs
     */
    void SwitchOff();
    
    /**
     * @brief Method to SwitchOff on TrafficLight
     * @details This method will make lightState Variable to False
     *
     * @coversreqs
     * @req{TRAFFIC_SIGNAL_5}
     * @endcoversreqs
     */
    bool getLightState();

    private:
    bool lightState;

};

#endif  //#ifndef  TRAFFILIGHT_HPP