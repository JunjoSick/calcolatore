cmake_minimum_required(VERSION 3.10)

# set the project name
set(PROJ Calculator)
project(${PROJ})

#c++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
add_link_options( /FORCE:MULTIPLE )
endif()

# add the executable
add_executable(${PROJ} "src/main.cpp" "src/vampire_numbers.cpp" "src/number_costraints.cpp" "src/calculator.cpp" src/utils.cpp)