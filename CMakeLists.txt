cmake_minimum_required(VERSION 3.16)
project(Benchmarks)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-O0")

set(TIMER_DIR "Timer")
set(SEQUENCE_DIR "Sequence_containers")
#set(ASSOCIATIVE_DIR "Associative_containers")
#set(UNORDERED_DIR "Unordered_containers")

include_directories(${SEQUENCE_DIR} ${TIMER_DIR})

set(SOURCE
        main.cpp
        ${TIMER_DIR}/Timer.h
        ${SEQUENCE_DIR}/Erase_sequence.h
        ${SEQUENCE_DIR}/Find_sequence.h
        ${SEQUENCE_DIR}/Insert_sequence.h
        Timer/Timer.h)

add_executable(Benchmarks ${SOURCE})

#add_executable(Benchmarks main.cpp Insert_sequence.h Erase_sequence.h Find_sequence.h Timer.h)


