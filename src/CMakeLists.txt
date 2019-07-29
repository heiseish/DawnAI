project(Dawn)

file(GLOB_RECURSE local_binary
    "*.cpp"
    "*.hpp"
)


add_executable(Dawn main.cpp ${local_binary} )
target_link_libraries(Dawn 
	PUBLIC 
		${TORCH_LIBRARIES}
        ${Boost_LIBRARIES}
		${OpenCV_LIBS}
)
set_property(
	TARGET 
		Dawn 
	PROPERTY 
		CXX_STANDARD 17
)




