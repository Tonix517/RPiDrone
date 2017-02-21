cmake_minimum_required (VERSION 3.6)
project (RpiDrone)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1)

file(GLOB SOURCES "*.cpp")
add_executable(RPiDrone ${SOURCES}) 

TARGET_LINK_LIBRARIES( RPiDrone
pthread
)
#add_executable(dacSignalTest dacSignalTest.cpp)

