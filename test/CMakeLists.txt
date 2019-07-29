file(GLOB_RECURSE src_lib
    "../src/*.cpp"
    "../src/*.hpp"
)


add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (Test ${src_files} ${src_lib})
target_link_libraries (Test
	PUBLIC
		${Boost_FILESYSTEM_LIBRARY}
		${Boost_SYSTEM_LIBRARY}
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
		${TORCH_LIBRARIES}
		${OpenCV_LIBS}
)

set_property(
	TARGET 
		Test 
	PROPERTY 
		CXX_STANDARD 17
)