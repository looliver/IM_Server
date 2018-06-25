cmake_minimum_required(VERSION 3.10)
project(cryptopp)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
        -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
        -DAC_HAS_DEBUG -DLINUX_DAEMON -Wno-deprecated -msse4.1 -m32)


aux_source_directory(./src SRC_LIST1)
set(EXECUTABLE_OUTPUT_PATH ./bin)
add_library(cryptopp STATIC ${SRC_LIST1})