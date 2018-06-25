cmake_minimum_required(VERSION 3.10)
PROJECT(fileserver)

AUX_SOURCE_DIRECTORY(./ SRC_LIST1)
AUX_SOURCE_DIRECTORY(../common/pb/protocol SRC_LIST2)

#SET(LIBRARY_OUTPUT_PATH ./)
SET(EXECUTABLE_OUTPUT_PATH  ./)
if(APPLE)
    SET(PB_LIB_DIR ../common/pb/lib/mac)
elseif(UNIX)
    SET(PB_LIB_DIR ../common/pb/lib/linux)
endif()


ADD_DEFINITIONS( -g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
        -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
        -DAC_HAS_DEBUG -DLINUX_DAEMON -std=c++11)

INCLUDE_DIRECTORIES(./ ../ ../common ../common/pb/protocol ../common/pb/)
LINK_DIRECTORIES(./ ../common ${PB_LIB_DIR} ../common/slog/lib)

#ADD_XXXX必须在TARGET_LINK_LIBRARIES前面，否则会报错
#ADD_LIBRARY(${PROJECTNAME} SHARED/STATIC ${SRC_LIST})
ADD_EXECUTABLE(file_server ${SRC_LIST1} ${SRC_LIST2})

TARGET_LINK_LIBRARIES(file_server pthread base protobuf-lite uuid slog)

