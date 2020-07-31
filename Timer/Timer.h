
#ifndef BENCHMARKS_TIMER_H
#define BENCHMARKS_TIMER_H

#include <chrono>
#include <iostream>

class Timer
{
public:
    using time_capture = std::chrono::time_point<std::chrono::system_clock>;
    time_capture start;
    time_capture end;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout<<duration.count()<<std::endl;
    }
};


#endif //BENCHMARKS_TIMER_H
