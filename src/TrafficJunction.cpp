#include "TrafficJunction.h"
#include <memory>
#include <vector>
using namespace std;

trafficJunctionResult
TrafficJunction::InitalizeTrafficPoles()
{
   trafficJunctionResult trafficJunctionResult1 = trafficJunctionResult::SUCCESS;
   if(mNoOfPole > 0)
   {
      for(int poleindex = 0 ; poleindex < mNoOfPole ; poleindex++)
      {
         std::unique_ptr<TrafficPole> ptr_traffic_pole = make_unique<TrafficPole>(); // Create unique pointer Traffic pole class
         vct_trafficpole.push_back(std::move(ptr_traffic_pole));    // store mNoOfPole number of unique pointer in vct_trafficpole vector
      }
   }
   else
   {
      trafficJunctionResult1 = trafficJunctionResult::ERROR_INVALID_NUMBER_OF_POLES;
   }
   return trafficJunctionResult1;
}

trafficJunctionResult 
TrafficJunction::AllowTraffic(int PoleNo)
{
   std::cout<<"Allowtraffic Poleno "<<PoleNo << " vct_trafficpole.size() "<< vct_trafficpole.size() <<std::endl;
   trafficJunctionResult trafficJunctionResult1 = trafficJunctionResult::SUCCESS;
   if((PoleNo > 0) && (PoleNo <= mNoOfPole))
   {
      for(int poleindex = 1; poleindex < vct_trafficpole.size() + 1; poleindex++)
      {
         if(poleindex != PoleNo)
         {
            vct_trafficpole[poleindex - 1]->Stop(); //turning off all pole except selected pole
            std::cout << "Stopped Pole number: "<< poleindex << std::endl;
         }
      } 
      vct_trafficpole[PoleNo - 1]->Go(); //turning on Green light for selected Pole
      std::cout << "Go Pole number: " << PoleNo << std::endl;
   }
   else
   {
      std::cout<<"Invalid Pole number\n";
      trafficJunctionResult1 = trafficJunctionResult::ERROR_INVALID_POLE_NUMBER;
   }
   m_get_active_pole_no = PoleNo;
   return trafficJunctionResult1;
}

void 
TrafficJunction::DisableTraffic() 
{
   for(int poleindex = 0; poleindex < vct_trafficpole.size(); poleindex++)
   {
      vct_trafficpole[poleindex]->Stop(); // call Stop such that all pole should turn on red light
   }
}

void 
TrafficJunction::EnableSlowDown() 
{ 
   for(int poleindex = 0; poleindex < vct_trafficpole.size(); poleindex++)
   {
      vct_trafficpole[poleindex]->SlowDown();  // call Slowdown such that all pole should blink yellow light
      std::cout<<"SlowDown pole no " << poleindex +1 <<std::endl;
   }   
}

int 
TrafficJunction::get_active_pole_no(){
   return m_get_active_pole_no;
}

int 
TrafficJunction::getNoOfPole(){
   return mNoOfPole;
}