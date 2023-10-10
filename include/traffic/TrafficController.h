#ifndef TRAFFICCONTROLLER_HPP
#define TRAFFICCONTROLLER_HPP

#include "TrafficJunction.h"
#include <queue>
enum Mode{
    Invalid,
    Auto,
    Manual,
    Night 
};
void handle_traffic_control(TrafficJunction* tTraffiObj);
void startautomode(int timer,TrafficJunction* tTraffiObj);
static Mode getMode();
static void setmode(Mode mode);
static Mode CurrentMode = Mode::Auto;


Mode
getMode()
{
    return CurrentMode;
}
void setmode(Mode mode)
{
    CurrentMode = mode;
}
//int TrafficJunction::m_get_active_pole_no; // allocated storage space for the static variable(otherwise will throw error undefined reference to `TrafficJunction::m_get_active_pole_no')
class TrafficController
{
    public:
    TrafficJunction* tTraffiObj = new TrafficJunction(4);
    TrafficController()
    {
        initilizetrafficcontrol();
    }
    ~TrafficController()
    {
        delete tTraffiObj;
    }
    void initilizetrafficcontrol();
    void setMode(enum Mode);
    static void acceptUserInput();
    static std::queue<char> mInputQueue;
     
    
    //static void startautomode(int timer);
    //int noofPoles = 3;
    
    //std::thread mThread_handle_automde;
    
    
    private:
    std::thread mThread_userinput; // To get user input from 
    std::thread mHandle_traffic_control; // TO handle traffic control (whether mode is auto or manual)
};

#endif  //#ifndef TRAFFICCONTROLLER_HPP