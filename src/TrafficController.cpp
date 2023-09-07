#include "TrafficController.h"
#include "TrafficJunction.h"
#include <chrono>
#include <thread>

Mode
getMode()
{
    return CurrentMode;
}

void handle_traffic_control(Mode mode,TrafficJunction* tTraffiObj)
{
   
   if(mode = Mode::Auto)
   {
       // start thread mThread_handle_automde 
    int x=1000;
    std::thread mThread_handle_automde(startautomode,x,tTraffiObj);
   }
   else
   {
       //stop timer

       
   }
   //read condition variable
   //wait untill thread stops

}

void
TrafficController::initilizetrafficcontrol(){
    mHandle_traffic_control = std::thread(handle_traffic_control,Mode::Auto,tTraffiObj);
    //std::thread ( userinput)
}

void 
startautomode(int timer ,TrafficJunction* tTraffiObj)
{
   // TrafficJunction* tTraffiObj = new TrafficJunction(4);
    int currerntActivepole = tTraffiObj->get_active_pole_no();
    int totalPoles = tTraffiObj->getNoOfPole();
    while(Mode::Auto == getMode())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(timer));    
        trafficJunctionResult t = tTraffiObj->AllowTraffic( (currerntActivepole + 1) % totalPoles );
    }
}
