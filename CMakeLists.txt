cmake_minimum_required(VERSION 3.10)

# set the project name
set(PROJ Calcolatore)
project(${PROJ})

#c++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(${PROJ} main.cpp risolutore_equazioni.cpp)