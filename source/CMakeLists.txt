


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(algorithms)
add_subdirectory(structures)

install(DIRECTORY structures 
	DESTINATION $ENV{HOME}/.include/my_lib
	PATTERN "*.cpp" EXCLUDE
	PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
	                    GROUP_EXECUTE GROUP_READ)
install(DIRECTORY algorithms 
	DESTINATION $ENV{HOME}/.include/my_lib
	PATTERN "*.cpp" EXCLUDE
	PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
	                    GROUP_EXECUTE GROUP_READ)


add_subdirectory(problems)
add_subdirectory(tests)
