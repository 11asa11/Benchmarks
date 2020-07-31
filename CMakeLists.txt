cmake_minimum_required(VERSION 3.16)
project(Benchmarks)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-O0")

add_executable(Benchmarks main.cpp Insert_sequence.h Erase_sequence.h Find_sequence.h Timer.h)


