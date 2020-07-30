
#ifndef BENCHMARKS_FIND_H
#define BENCHMARKS_FIND_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>
#include <algorithm>
#include <deque>

namespace Find {

    void containers_find() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size, 1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Find element" << std::endl;

        vec.insert(vec.begin() + vec.size() / 2, 9);
        auto start = std::chrono::high_resolution_clock::now();
        std::find(vec.begin(),vec.end(),9);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector = end - start;

        deq.insert(deq.begin() + deq.size() / 2, 9);
        start = std::chrono::high_resolution_clock::now();
        std::find(deq.begin(),deq.end(),9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_deque = end - start;

        auto it = lst.begin();
        std::advance(it, lst.size() / 2);
        lst.insert(it, 9);
        start = std::chrono::high_resolution_clock::now();
        std::find(lst.begin(),lst.end(),9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_list = end - start;

        auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
        f_lst.insert_after(before_middle, 9);
        start = std::chrono::high_resolution_clock::now();
        std::find(f_lst.begin(),f_lst.end(),9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_f_list = end - start;

        std::cout << "vector time: " << duration_vector.count() << std::endl;
        std::cout << "deque time: "<< duration_deque.count()<< std::endl;
        std::cout << "list time: " << duration_list.count() << std::endl;
        std::cout << "forward_list time: " << duration_f_list.count() << std::endl;
    }

    void start_insert_test() {
        containers_find();
    }
}

#endif //BENCHMARKS_FIND_H
