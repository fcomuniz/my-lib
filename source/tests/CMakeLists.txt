# Enable ExternalProject CMake modules
# We need thread support
find_package(Threads REQUIRED)

include(ExternalProject)
ExternalProject_Add(
        googletest
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        GIT_REPOSITORY "https://github.com/google/googletest.git"
        GIT_TAG master
        INSTALL_COMMAND ""
        UPDATE_DISCONNECTED 1
)

ExternalProject_Get_Property(googletest source_dir binary_dir)

set_directory_properties(${binary_dir} CLEAN_NO_CUSTOM 1)

add_library(libgtest IMPORTED STATIC)
add_dependencies(libgtest googletest)

set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
        )

include_directories(${source_dir}/googletest/include)


add_library(libgmock IMPORTED STATIC)

set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
#	include_directories("${source_dir}/include")

include_directories(${source_dir}/googlemock/include)
set(UNIT_TEST_EXEC ${CMAKE_CURRENT_SOURCE_DIR}/UnitTestExec.cpp)
file(GLOB_RECURSE TEST_SRCS *UnitTest.cpp)

foreach(test ${TEST_SRCS})
  get_filename_component(filename_we ${test} NAME_WE)
  get_filename_component(dir ${test} DIRECTORY)
  add_executable(${filename_we} ${test} ${UNIT_TEST_EXEC})
  target_link_libraries(${filename_we} libgtest libgmock algorithms structures)
  file(GLOB_RECURSE txts ${dir}/*.txt)
  foreach(txt ${txts})
	  get_filename_component(txt_name ${txt} NAME)
	  add_custom_command(
			  TARGET ${filename_we} POST_BUILD
			  DEPENDS ${filename_we}
			  COMMAND ${CMAKE_COMMAND} -E create_symlink   ${txt} $<TARGET_FILE_DIR:${filename_we}>/${txt_name} 
			  COMMENT "Copying ${txt}"
		  )

  endforeach()
endforeach()
if(TEST_SRCS)
	add_executable(all_tests ${TEST_SRCS} ${UNIT_TEST_EXEC})
	target_link_libraries(all_tests libgtest libgmock algorithms structures)
endif()
