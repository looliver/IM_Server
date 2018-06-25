cmake_minimum_required(VERSION 3.10)
project(IM_Server)

set(CMAKE_CXX_STANDARD 11)


add_definitions(-g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
        -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
        -DAC_HAS_DEBUG -DLINUX_DAEMON -std=c++11 -m32)
add_subdirectory(file_server)
add_subdirectory(common)

include_directories(./external/jsoncpp/include)
link_directories(./external/jsoncpp/prebuilt/win32)


include_directories(./external/glog/include)
link_directories(./external/glog/prebuilt/win32)
#
#include_directories(./external/protobuf/include)
#link_directories(./external/protobuf/prebuilt/win)


add_executable(IM_Server main.cpp)
target_link_libraries(IM_Server jsoncpp glog)

