cmake_minimum_required (VERSION 3.15)
project (Dawn)

option(BUILD_LOCAL "Build local instead of docker" OFF) #OFF by default
message("BUILD LOCAL is ${BUILD_LOCAL}")
if(BUILD_LOCAL)
    find_package(OpenCV 4.1.0 EXACT REQUIRED PATHS /usr/local/Cellar/opencv/lib/cmake/opencv4)
    set(Boost_INCLUDE_DIRS /usr/local/Cellar/boost/1.69.0_2/include)
    set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/dependencies/libtorch_macosx;${CMAKE_PREFIX_PATH}")
else()
    find_package(OpenCV COMPONENTS core highgui imgproc imgcodecs REQUIRED)
    set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/dependencies/libtorch;${CMAKE_PREFIX_PATH}")
endif(BUILD_LOCAL)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Torch REQUIRED)
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED) 


include_directories(
    ${CMAKE_SOURCE_DIR}/include 
    ${CMAKE_SOURCE_DIR}/src 
    ${Boost_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
    ${OPENMP_LIBRARIES}
    ${OPENMP_INCLUDES}
)

add_subdirectory (src) 
add_subdirectory (test)
enable_testing ()
add_test (NAME MyTest COMMAND Test)
