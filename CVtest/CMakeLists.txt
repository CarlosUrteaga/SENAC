cmake_minimum_required(VERSION 2.8)
project( CVtest )
find_package( OpenCV REQUIRED )
add_executable( CVtest DisplayImage.cpp )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( CVtest ${OpenCV_LIBS} )
