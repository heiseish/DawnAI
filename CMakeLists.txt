cmake_minimum_required (VERSION 3.10)
project (Dawn)

add_compile_options(-std=c++11)

list(APPEND CMAKE_PREFIX_PATH
"${CMAKE_SOURCE_DIR}/dep/protobuf"  
"${CMAKE_SOURCE_DIR}/dep/grpc"
"${CMAKE_SOURCE_DIR}/dep/libtorch"
"${CMAKE_SOURCE_DIR}/dep/opencv4"
)

# Cmake find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)
find_package(Torch REQUIRED)
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED) 
find_package(OpenCV COMPONENTS core highgui imgproc imgcodecs REQUIRED)


set(PROTOS
    ${CMAKE_CURRENT_SOURCE_DIR}/protos/text_generator_service.proto
)

set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto-src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})
include_directories(${PROTO_SRC_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})


include_directories(
    ${CMAKE_SOURCE_DIR}/include 
    ${CMAKE_SOURCE_DIR}/src 
    ${Boost_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
	${PROTO_SRC_DIR}
)

file(GLOB_RECURSE local_binary
    "src/*.cpp"
    "src/*.hpp"
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})

add_executable(Dawn src/server.cpp 
	${local_binary} 
	${PROTO_SRCS}
    ${GRPC_SRCS}
)

target_link_libraries(Dawn  
		${TORCH_LIBRARIES}
        ${Boost_LIBRARIES}
		${OpenCV_LIBS}
		gRPC::grpc++_reflection
		protobuf::libprotobuf
)

# add_subdirectory (src) 
# add_subdirectory (test)
# enable_testing ()
# add_test (NAME MyTest COMMAND Test)
