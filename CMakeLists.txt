cmake_minimum_required(VERSION 3.5)

project(Slide_average LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Slide_average main.cpp slide_average.h log_duration.h)
