
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


foreach(prob ${SRCS})
	get_filename_component(prob_we ${prob} NAME_WE)
	add_executable(${prob_we} ${SRCS} ${HDRS})
	target_link_libraries(${prob_we} algorithms structures)
endforeach()
