
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

namespace Find_sequence {

    std::size_t size = 100000;

    void containers_find() {
        Product product;
        Product prod_ins(10,101.0);
        std::vector<Product> vec(size, product);
        std::deque<Product> deq(size, product);
        std::list<Product> lst(size, product);
        std::forward_list<Product> f_lst(size, product);
        std::cout << "Find element" << std::endl;

        {
            vec.insert(vec.begin() + vec.size() / 2, prod_ins);
            Timer timer;
            std::find(vec.begin(),vec.end(),prod_ins);
            std::cout << "vector time: ";
        }

        {
            deq.insert(deq.begin() + deq.size() / 2, prod_ins);
            Timer timer;
            std::find(deq.begin(),deq.end(),prod_ins);
            std::cout << "deque time: ";
        }

        {
            auto it = lst.begin();
            std::advance(it, lst.size() / 2);
            lst.insert(it, prod_ins);
            Timer timer;
            std::find(lst.begin(),lst.end(),prod_ins);
            std::cout << "list time: ";
        }

        {
            auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
            f_lst.insert_after(before_middle, prod_ins);
            Timer timer;
            std::find(f_lst.begin(),f_lst.end(),prod_ins);
            std::cout << "forward_list time: ";
        }

    }

    void start_find_test() {
        containers_find();
    }
}

#endif //BENCHMARKS_FIND_H
