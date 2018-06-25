cmake_minimum_required(VERSION 3.10)
project(common)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
        -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
        -DAC_HAS_DEBUG -DLINUX_DAEMON -Wno-deprecated)


aux_source_directory(./src SRC_LIST1)

include_directories(../external/jsoncpp/include)
link_directories(../external/jsoncpp/prebuilt/win32)

include_directories(../external/glog/include)
link_directories(../external/glog/prebuilt/win32)

include_directories(../external/protobuf/include)
link_directories(../external/protobuf/prebuilt/win)



add_library(common STATIC ${SRC_LIST1})

set(EXECUTABLE_OUTPUT_PATH ./bin)

target_link_libraries(common pthread jsoncpp glogd protobuf-lited)