project(Dawn)

file(GLOB_RECURSE local_binary
    "*.cpp"
    "*.hpp"
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})

add_executable(Dawn server.cpp 
	${local_binary} 
	${PROTO_SRCS}
    ${GRPC_SRCS}
)

target_link_libraries(Dawn  
		${TORCH_LIBRARIES}
        ${Boost_LIBRARIES}
		${OpenCV_LIBS}
		${PROTOBUF_LIBRARY}
		gRPC::grpc++_reflection
		protobuf::libprotobuf
)
# set_property(TARGET Dawn PROPERTY CXX_STANDARD 17)




