cmake_minimum_required(VERSION 2.8)

project(SampleAplication)
add_executable(SampleAplication "main.cpp")
set(OpenCV_DIR "/usr/lib/opencv")
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(SampleAplication ${OpenCV_LIBS})
