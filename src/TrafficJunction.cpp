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

// logs everywhwere
trafficJunctionResult 
TrafficJunction::AllowTraffic(int PoleNo)
{
   trafficJunctionResult trafficJunctionResult1 = trafficJunctionResult::SUCCESS;
   if((PoleNo > 0) && (PoleNo < mNoOfPole))
   {
      //try catch
      for(int poleindex = 0; poleindex < vct_trafficpole.size(); poleindex++)
      {
         if(poleindex != PoleNo-1)
         {
            vct_trafficpole[poleindex]->Stop(); //turning off all pole except selected pole
            std::cout << "Stopped Pole number: "<< poleindex+1 << std::endl;
         }
      } 
      vct_trafficpole[PoleNo - 1]->Go(); //turning on Green light for selected Pole
      std::cout << "Go Pole number: "<< PoleNo << std::endl;
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
TrafficJunction::DisableTraffic() //TODO : change to i to poleindex
{
   for(int poleindex = 0; poleindex < vct_trafficpole.size(); poleindex++)
   {
      vct_trafficpole[poleindex]->Stop(); // call Stop such that all pole should turn on red light
   }
}

void 
TrafficJunction::EnableSlowDown() //TODO : change to i to poleindex
{ 
   for(int poleindex = 0; poleindex < vct_trafficpole.size(); poleindex++)
   {
      vct_trafficpole[poleindex]->SlowDown();  // call Slowdown such that all pole should blink yellow light
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