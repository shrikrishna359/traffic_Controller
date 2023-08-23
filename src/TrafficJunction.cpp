#include "TrafficJunction.h"
#include <memory>
#include <vector>
using namespace std;

void
TrafficJunction::InitalizeTrafficPoles()
{
   for(int i = 0 ; i < mNoOfPole ; i++)
   {
      std::unique_ptr<TrafficPole> ptr_traffic_pole = make_unique<TrafficPole>(); // Create unique pointer Traffic pole class
      vct_trafficpole.push_back(std::move(ptr_traffic_pole));    // store mNoOfPole number of unique pointer in vct_trafficpole vector
   }
}

void 
TrafficJunction::AllowTraffic(int PoleNo)
{
   if((PoleNo > 0) && (PoleNo < mNoOfPole))
   {
      for(int i = 0; i < vct_trafficpole.size(); i++)
      {
         if(i != PoleNo-1)
         {
            vct_trafficpole[i]->Stop(); //turning off all pole except selected pole
         }
      } 
      vct_trafficpole[PoleNo - 1]->Go(); //turning on Green light for selected Pole
   }
}

void 
TrafficJunction::DisableTraffic()
{
   for(int i = 0; i < vct_trafficpole.size(); i++)
   {
      vct_trafficpole[i]->Stop(); // call Stop such that all pole should turn on red light
   }
}

void 
TrafficJunction::EnableSlowDown()
{ 
   for(int i = 0; i < vct_trafficpole.size(); i++)
   {
      vct_trafficpole[i]->SlowDown();  // call Slowdown such that all pole should blink yellow light
   }   
}