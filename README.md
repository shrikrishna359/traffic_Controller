# traffic_Controller

prerequisite

1.ubuntu os required

2.Cmake installed

	- sudo apt  install cmake
 
3.Gtest installed

	- sudo apt-get install libgtest-dev
 
	- cd /usr/src/gtest
 
	- sudo cmake CMakeLists.txt
 
	- sudo make
 
	- cd lib/
 
	- sudo cp *.a /usr/lib
 

Clone Project :- git clone https://github.com/shrikrishna359/traffic_Controller.git

How to build?

1.Create directory build

	developer@developer-VirtualBox:~/traffic/traffic_Controller$ mkdir build

2.go to build folder

	developer@developer-VirtualBox:~/traffic/traffic_Controller$ cd build/
	
3.run cmake ..

	developer@developer-VirtualBox:~/traffic/traffic_Controller/build$ cmake ..

4.run make command

	developer@developer-VirtualBox:~/traffic/traffic_Controller/build$ make
	
Run Gtest :- developer@developer-VirtualBox:~/traffic/traffic_Controller/build$ ./test/testGtest



