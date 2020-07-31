
#ifndef BENCHMARKS_FIND_H
#define BENCHMARKS_FIND_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>
#include <algorithm>
#include <deque>
#include "Timer.h"

namespace Find {

    void containers_find() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size, 1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Find element" << std::endl;

        {
            vec.insert(vec.begin() + vec.size() / 2, 9);
            Timer timer;
            std::find(vec.begin(),vec.end(),9);
            std::cout << "vector time: ";
        }

        {
            deq.insert(deq.begin() + deq.size() / 2, 9);
            Timer timer;
            std::find(deq.begin(),deq.end(),9);
            std::cout << "deque time: ";
        }

        {
            auto it = lst.begin();
            std::advance(it, lst.size() / 2);
            lst.insert(it, 9);
            Timer timer;
            std::find(lst.begin(),lst.end(),9);
            std::cout << "list time: ";
        }

        {
            auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
            f_lst.insert_after(before_middle, 9);
            Timer timer;
            std::find(f_lst.begin(),f_lst.end(),9);
            std::cout << "forward_list time: ";
        }

    }

    void start_insert_test() {
        containers_find();
    }
}

#endif //BENCHMARKS_FIND_H
