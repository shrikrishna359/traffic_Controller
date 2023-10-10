#include "TrafficController.h"
#include "TrafficJunction.h"
#include <chrono>
#include <thread>
#include <condition_variable>

std::condition_variable cv;
std::mutex m;

std::queue<char> TrafficController::mInputQueue;


void handle_traffic_control(TrafficJunction* tTraffiObj)
{
    std::cout<<"Entered handle traffic control"<<std::endl;
   std::unique_lock<std::mutex> ul(m);
   cv.wait(ul,[]{return TrafficController::mInputQueue.empty() == 0;});

   if(TrafficController::mInputQueue.front() == 'A')
   {
       // start thread mThread_handle_automde 
       TrafficController::mInputQueue.pop();
    setmode(Mode::Auto);
    int x=1000;
    std::thread mThread_handle_automde(startautomode,x,tTraffiObj);
    mThread_handle_automde.join();   
   }
   else if(TrafficController::mInputQueue.front() == 'M')
   {
       TrafficController::mInputQueue.pop();
       int n;
       std::cout<<TrafficController::mInputQueue.size()<<" size of input vector \n";
       std::cout<<"enter no\n";
       std::cin>> n;
       std::cout <<"entered no "<<n<<"\n";
       TrafficController::mInputQueue.push(n);
        setmode(Mode::Manual);
       // if(!TrafficController::mInputQueue.empty() && TrafficController::mInputQueue.front() > 0 && TrafficController::mInputQueue.front() < tTraffiObj->getNoOfPole())
       // {
            tTraffiObj->AllowTraffic(TrafficController::mInputQueue.front());
       // }
        TrafficController::mInputQueue.pop();
   }
   else if(TrafficController::mInputQueue.front() == 'N')
   {
       TrafficController::mInputQueue.pop();
        setmode(Mode::Night);
        tTraffiObj->EnableSlowDown();     
   }
    
}

void
TrafficController::initilizetrafficcontrol(){
    mHandle_traffic_control = std::thread(handle_traffic_control,tTraffiObj);
    mThread_userinput = std::thread (acceptUserInput);
    mThread_userinput.join();
    mHandle_traffic_control.join();
}

void
TrafficController::acceptUserInput()
{
    char c;
    while(1)
    {
        std::cerr<<"Entered accept user input"<<std::endl;
        std::unique_lock<std::mutex> ul(m);
        std::cin>>c;
        if( c =='A' || c == 'M' || c == 'N' || (c >'0' && c < '9')){
            mInputQueue.push(c);
        }
        std::cout<<"mInputQueue zize() "<<TrafficController::mInputQueue.size()<<std::endl;
        cv.notify_all();
    }
    
}

void 
startautomode(int timer ,TrafficJunction* tTraffiObj)
{
    int currerntActivepole = tTraffiObj->get_active_pole_no();
    int localcurrerntActivepole = currerntActivepole;
    int totalPoles = tTraffiObj->getNoOfPole();
    while(Mode::Auto == getMode())
    {
        std::cout<<"IN AutoMode\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(timer));    
        trafficJunctionResult t = tTraffiObj->AllowTraffic( (localcurrerntActivepole + 1) % totalPoles );
        localcurrerntActivepole++;
    }
}
