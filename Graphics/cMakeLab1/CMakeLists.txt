#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(cMakeLab1)

#This tells CMake to fib.c and name it fibonacci
add_executable(test1 test1_main.cpp class1.h class1.cpp)
