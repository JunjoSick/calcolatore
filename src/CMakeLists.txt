cmake_minimum_required(VERSION 3.10)

# set the project name
set(PROJ Calculator)
project(${PROJ})

#c++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(${PROJ} "main.cpp" "vampire_numbers.cpp" "number_costraints.hpp" "function.cpp")