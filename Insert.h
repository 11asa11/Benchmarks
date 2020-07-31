
#ifndef BENCHMARKS_INSERT_H
#define BENCHMARKS_INSERT_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>
#include <deque>
#include "Timer.h"

namespace Insert {

    void containers_insert_begin() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Insert at the BEGINNING" << std::endl;

        {
            Timer timer;
            vec.insert(vec.begin(), 9);
            std::cout << "vector time_reallocate: ";
        }

        {
            Timer timer;
            vec.insert(vec.begin(), 9);
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.push_front(9);
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            lst.push_front(9);
            std::cout << "list time: ";
        }

        {
            Timer timer;
            f_lst.push_front(9);
            std::cout << "forward_list time: ";
        }

    }

    void containers_insert_end() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Insert at the END" << std::endl;

        // reallocate
        {
            Timer timer;
            vec.push_back(9);
            std::cout << "vector time_reallocate: ";
        }

        {
            Timer timer;
            vec.push_back(9);
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.push_back(9);
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            lst.push_back(9);
            std::cout << "list time: ";
        }

        {
            Timer timer;
            auto before_end = std::next(f_lst.begin(), std::distance(f_lst.begin(), f_lst.end()) - 1);
            f_lst.insert_after(before_end, 9);
            std::cout << "forward_list time: ";
        }
    }

    void containers_insert_middle() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Insert at the MIDDLE" << std::endl;

        // reallocate
        {
            Timer timer;
            vec.insert(vec.begin() + vec.size() / 2, 9);
            std::cout << "vector time_reallocate: ";
        }

        {
            Timer timer;
            vec.insert(vec.begin() + vec.size() / 2, 9);
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.insert(deq.begin() + deq.size() / 2, 9);
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            auto it = lst.begin();
            std::advance(it, lst.size() / 2);
            lst.insert(it, 9);
            std::cout << "list time: ";
        }

        {
            Timer timer;
            auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
            f_lst.insert_after(before_middle, 9);
            std::cout << "forward_list time: ";
        }

    }

    void start_insert_test() {
        containers_insert_begin();
        std::cout << std::endl;
        containers_insert_end();
        std::cout << std::endl;
        containers_insert_middle();
    }
}
#endif //BENCHMARKS_INSERT_H
