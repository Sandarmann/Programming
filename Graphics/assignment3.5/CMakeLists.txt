#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(FRAME)

#This includes the directories so I don't have to do longer names in the headers.
include_directories(${PROJECT_SOURCE_DIR}/Vectors)
include_directories(${PROJECT_SOURCE_DIR}/Objects)

add_subdirectory(Vectors)
add_subdirectory(Objects)

#Creates a alias to the main.cpp as our main file to run through with the make file command ot link it to the executable name 
#frame
add_executable(frame main.cpp)

#This tells CMake to fib.c and name it fibonacci
add_library(Main FrameBuffer.h FrameBuffer.cpp)

#Links the frame with the main.cpp to the other files in the directories.
target_link_libraries(frame Main Vectors Objects)

