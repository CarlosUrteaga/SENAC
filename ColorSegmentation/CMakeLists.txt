cmake_minimum_required(VERSION 2.8)
project( ColorSegmentation )
find_package( OpenCV REQUIRED )
add_executable( ColorSegmentation DisplayImage.cpp )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( ColorSegmentation ${OpenCV_LIBS} )
