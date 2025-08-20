cmake_minimum_required(VERSION 3.11)

project(Video2jpg)

find_package(OpenCV REQUIRED)
find_package(fmt REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Video2jpg Video2jpg.cpp)

target_link_libraries(Video2jpg ${OpenCV_LIBS})
target_link_libraries(Video2jpg fmt::fmt)