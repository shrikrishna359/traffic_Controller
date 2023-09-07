project(Traffic_Controller)
add_compile_options(-pthread)
add_library(Traffic TrafficLight.cpp TrafficPole.cpp TrafficJunction.cpp TrafficController.cpp)
target_include_directories(Traffic 
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include/traffic
)