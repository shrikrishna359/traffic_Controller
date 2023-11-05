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
    while(1){
       
     Mode prevMode = Mode::Invalid;  
   // std::cout<<"Entered handle traffic control"<<std::endl;
    //std::cout << "TrafficController::mInputQueue" << TrafficController::mInputQueue.front()<<std::endl; 
    //std::unique_lock<std::mutex> ul(m);
    //cv.wait(ul,[]{return TrafficController::mInputQueue.empty() == 0;});

   if(TrafficController::mInputQueue.front() == 'A')
   {
       if(prevMode != Mode::Auto){
       // start thread mThread_handle_automde 
    std::cout << "Entered handle traffic control A " << std::endl;
    TrafficController::mInputQueue.pop();
    setmode(Mode::Auto);
    int x=1000;
    std::thread mThread_handle_automde(startautomode,x,tTraffiObj);
    mThread_handle_automde.join();  
    prevMode =  Mode::Auto;
       }
       else{
           TrafficController::mInputQueue.pop();
       }
   }
   else if(TrafficController::mInputQueue.front() == 'M')
   {
       if(prevMode!= Mode::Manual){
       TrafficController::mInputQueue.pop();
       int n;
       std::cout << "Entered manaual input " << std::endl;
       std::cout<<TrafficController::mInputQueue.size()<<" size of input vector \n";
       //std::cout<<"enter no\n";
       //std::cin>> n;
       //std::cout <<"entered no "<<n<<"\n";
       //TrafficController::mInputQueue.push(n);
       setmode(Mode::Manual);
        while (getMode() == Mode::Manual){
           for (int i = 0;i<10 ;i++){
               if(TrafficController::mInputQueue.empty()){
                std::cout << "waiting for manaual input" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
               }
               else
               {             
                   break;
               }
           }
           if(static_cast<int>(TrafficController::mInputQueue.front()) - '0' > 0 && static_cast<int>(TrafficController::mInputQueue.front())- '0'< 9){
            tTraffiObj->AllowTraffic(static_cast<int>(TrafficController::mInputQueue.front()- '0'));
            //Input.manualInput.pop();
            TrafficController::mInputQueue.pop();
           }
           else if (TrafficController::mInputQueue.front() == 'A')
           {
               setmode(Mode::Auto);
           }
           else if (TrafficController::mInputQueue.front() == 'N')
           {
               setmode(Mode::Night);
           }
           else {
               setmode(Mode::Invalid);
           }
            }
        std::cout << "exit manual" << std::endl;
        prevMode =  Mode::Manual;
       }
       else{
          TrafficController::mInputQueue.pop(); 
       }
   }
   else if(TrafficController::mInputQueue.front() == 'N')
   {
       if(prevMode!= Mode::Night){
       TrafficController::mInputQueue.pop();
       prevMode =  Mode::Night; 
        setmode(Mode::Night);
        tTraffiObj->EnableSlowDown(); 
       }
       else{
           TrafficController::mInputQueue.pop();
       }
        
   }
   else if((TrafficController::mInputQueue.front() == 'D') && (prevMode != Mode::Disable))
   {
       if(prevMode!= Mode::Disable){
       setmode(Mode::Disable);
       prevMode =  Mode::Disable; 
       TrafficController::mInputQueue.pop();
       tTraffiObj->DisableTraffic();
       std::cout << " Disable Mode " << std::endl;
       }
       else{
           TrafficController::mInputQueue.pop();
       }
       
   }
   else{
      // std::cout << " Invalid" << std::endl;
       setmode(Mode::Invalid);
   }
  // std::cout << "exit handle_traffic_control TrafficController::mInputQueue" << TrafficController::mInputQueue.front()<<std::endl; 
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
    while(1){
        std::cout<<"Entered accept user input"<<std::endl;
       // std::unique_lock<std::mutex> ul(m);
        std::cin>>c;
        // if( c =='A' || c == 'N' ){
        //     mInputQueue.push(c);
        //     Input.userinput = c;
        // }
        // else if( c == 'M' )
        // {
        //     mInputQueue.push(c);
        //     setmode(Mode::Manual);
        //     std::cout << "Enter manaul Input " << std::endl;
        //     char manaualInput;
        //     std::cin >> manaualInput;
        //     mInputQueue.push(manaualInput);
        //     Input.manualInput.push(manaualInput);
        // }
        mInputQueue.push(c);
        std::cout<<"mInputQueue size() "<<TrafficController::mInputQueue.size()<<std::endl;
       // cv.notify_all();
        
    }
}

void 
startautomode(int timer ,TrafficJunction* tTraffiObj)
{
    int currerntActivepole = tTraffiObj->get_active_pole_no();
    int localcurrerntActivepole = currerntActivepole;
    int totalPoles = tTraffiObj->getNoOfPole();
    while(TrafficController::mInputQueue.empty())
    {
        std::cout<<"IN AutoMode\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(timer));    
        trafficJunctionResult t = tTraffiObj->AllowTraffic( ((localcurrerntActivepole ) % totalPoles) + 1 );
        localcurrerntActivepole++;
    }
}
