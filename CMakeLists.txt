cmake_minimum_required(VERSION 3.9)
project(TransitProgram)

set(CMAKE_CXX_STANDARD 11)

add_executable(TransitProgram main.cpp Users.cpp Users.h Transport.cpp Transport.h Passenger.cpp Passenger.h Admin.cpp Admin.h Driver.cpp Driver.h)