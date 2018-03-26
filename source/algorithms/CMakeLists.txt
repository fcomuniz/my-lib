
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

message(WARNING ${SRCS})

if(SRCS)
	add_library(algorithms ${SRCS} ${HDRS})
endif()
