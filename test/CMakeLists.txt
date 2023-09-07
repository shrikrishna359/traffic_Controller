project(Traffic_Controller)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE UNIT_TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(ALL_CPP_UNIT_TEST_FILES ${UNIT_TEST_FILES})
file(GLOB MAIN_SOURCE 
${CMAKE_SOURCE_DIR}/src/*.cpp
)

list(APPEND ALL_CPP_UNIT_TEST_FILES ${MAIN_SOURCE})
add_executable(testGtest ${ALL_CPP_UNIT_TEST_FILES})
target_link_libraries(testGtest ${GTEST_LIBRARIES} pthread )
target_include_directories(testGtest 
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include/traffic
)