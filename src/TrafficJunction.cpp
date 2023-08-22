#include "TrafficJunction.h"
#include <memory>
#include <vector>
using namespace std;

void
TrafficJunction::InitalizeTrafficPoles()
{
   for(int i = 0 ; i < mNoOfPole ; i++)
   {
      std::unique_ptr<TrafficPole> ptr_traffic_pole = make_unique<TrafficPole>();
      vct_trafficpole.push_back(std::move(ptr_traffic_pole));
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
      vct_trafficpole[PoleNo - 1]->Go();
   }
}

void 
TrafficJunction::DisableTraffic()
{
   for(int i = 0; i < vct_trafficpole.size(); i++)
   {
      vct_trafficpole[i]->Stop();
   }
}

void 
TrafficJunction::EnableSlowDown()
{
   DisableTraffic();
   for(int i = 0; i < vct_trafficpole.size(); i++)
   {
      vct_trafficpole[i]->SlowDown();
   }   
}