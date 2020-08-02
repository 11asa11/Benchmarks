cmake_minimum_required(VERSION 3.16)
project(Benchmarks)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-O3")

set(MY_CLASS_DIR "MyClass")
set(TIMER_DIR "Timer")
set(SEQUENCE_DIR "Sequence_containers")
set(ASSOCIATIVE_DIR "Associative_containers")
set(UNORDERED_DIR "Unordered_containers")

include_directories(${SEQUENCE_DIR} ${MY_CLASS_DIR} ${TIMER_DIR} ${ASSOCIATIVE_DIR} ${UNORDERED_DIR})

set(SOURCE
        main.cpp
        ${MY_CLASS_DIR}/Product.h
        ${TIMER_DIR}/Timer.h
        ${SEQUENCE_DIR}/Erase_sequence.h
        ${SEQUENCE_DIR}/Find_sequence.h
        ${SEQUENCE_DIR}/Insert_sequence.h
        ${ASSOCIATIVE_DIR}/Erase_associative.h
        ${ASSOCIATIVE_DIR}/Find_associative.h
        ${ASSOCIATIVE_DIR}/Insert_associative.h
        ${UNORDERED_DIR}/Erase_unordered.h
        ${UNORDERED_DIR}/Find_unordered.h
        ${UNORDERED_DIR}/Insert_unordered.h
        )

add_executable(Benchmarks ${SOURCE})

#add_executable(Benchmarks main.cpp Insert_sequence.h Erase_sequence.h Find_sequence.h Timer.h)


