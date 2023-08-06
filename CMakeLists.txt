cmake_minimum_required(VERSION 3.16.3)

project(Traffic_Controller)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()


add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(main)  
add_subdirectory(test)  