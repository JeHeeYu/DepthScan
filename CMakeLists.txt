cmake_minimum_required(VERSION 3.10)
project(DepthScan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(realsense2 REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
    ${realsense2_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS} 
)

set(PROJECT_SOURCES
    src/main.cpp
)

add_executable(DepthScan ${PROJECT_SOURCES})

target_link_libraries(DepthScan PRIVATE 
    realsense2::realsense2 ${OpenCV_LIBS}
)
