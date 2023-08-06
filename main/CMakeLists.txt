project(Traffic_Controller)
add_executable(Traffic_Controller main.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

target_link_libraries(Traffic_Controller PRIVATE gcov)

target_link_libraries(Traffic_Controller
       PRIVATE
       Traffic
)

target_include_directories(Traffic 
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include/traffic
)
