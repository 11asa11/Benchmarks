
#ifndef BENCHMARKS_ERASE_H
#define BENCHMARKS_ERASE_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>
#include <deque>
#include "Timer.h"

namespace Erase {

    void containers_erase_begin() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Erase at the BEGINNING" << std::endl;

        {
            Timer timer;
            vec.erase(vec.begin());
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.pop_front();
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            lst.pop_front();
            std::cout << "list time: ";
        }

        {
            Timer timer;
            f_lst.pop_front();
            std::cout << "forward_list time: ";
        }

    }

    void containers_erase_end() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Erase at the END" << std::endl;

        {
            Timer timer;
            vec.pop_back();
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.pop_back();
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            lst.pop_back();
            std::cout << "list time: ";
        }

        {
            Timer timer;
            auto before_end = std::next(f_lst.begin(), std::distance(f_lst.begin(), f_lst.end()) - 2);
            f_lst.erase_after(before_end);
            std::cout << "forward_list time: ";
        }

    }

    void containers_erase_middle() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Erase at the MIDDLE" << std::endl;

        {
            Timer timer;
            vec.erase(vec.begin() + vec.size() / 2);
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.erase(deq.begin() + deq.size() / 2);
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            auto it = lst.begin();
            std::advance(it, lst.size() / 2);
            lst.erase(it);
            std::cout << "list time: ";
        }

        {
            Timer timer;
            auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
            f_lst.erase_after(before_middle);
            std::cout << "forward_list time: ";
        }

    }

    void start_erase_test() {
        containers_erase_begin();
        std::cout << std::endl;
        containers_erase_end();
        std::cout << std::endl;
        containers_erase_middle();
    }
}

#endif //BENCHMARKS_ERASE_H
