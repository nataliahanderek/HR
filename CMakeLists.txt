cmake_minimum_required( VERSION 3.0 )

project( lab6 )

include_directories( ./include ./src )

add_executable(test ./src/main.cpp ./src/hrms.cpp ./src/employee.cpp)