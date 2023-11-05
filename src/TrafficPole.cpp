#include "TrafficPole.h"
#include <chrono>
#include <thread>

void
TrafficPole::Stop()
{
   //check whether Pole already is in stop state
   if(stop != e_poleState)
   {
      obj_Green_Light.SwitchOff();
      obj_Yellow_Light.SwitchOn();
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      obj_Green_Light.SwitchOff();
      obj_Red_Light.SwitchOn();
      e_poleState = stop;
   }   
}

void
TrafficPole::Go()
{
   //check whether Pole already is in Go state
   if(go != e_poleState)
   {
      obj_Red_Light.SwitchOff();
      obj_Yellow_Light.SwitchOn();
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));  //delay for sec
      obj_Yellow_Light.SwitchOff();
      obj_Green_Light.SwitchOn();  
      e_poleState = go;
   }
}

void
TrafficPole::SlowDown()
{
   //check whether Pole already is in SlowDown state
   if(slowDown != e_poleState)
   {
      obj_Red_Light.SwitchOff();
      obj_Green_Light.SwitchOff();
      e_poleState = slowDown;
      mThreadSlowdown = std::thread(&TrafficPole::SlowdownThreadHandler,TrafficPole()); //started thread to blink yellow light
      mThreadSlowdown.detach();
      //std::cout<<"SlowDown SlowDown"<<std::endl;
   }  
}

//Threadhandler function for blinking yellow light
void
TrafficPole::SlowdownThreadHandler()
{
   while(slowDown != e_poleState){
      obj_Yellow_Light.SwitchOn();
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
     // std::cout<<"SlowdownThreadHandler function "<<std::endl;
      obj_Yellow_Light.SwitchOff();
   }
}