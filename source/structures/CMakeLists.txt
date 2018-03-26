# Enable ExternalProject CMake modules
# We need thread support
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} PUBLIC)

if(SRCS)
	add_library(structures ${SRCS})
	INSTALL(TARGETS structures
		ARCHIVE DESTINATION ~/.bin
		)

endif()

