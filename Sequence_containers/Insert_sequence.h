
#ifndef BENCHMARKS_INSERT_H
#define BENCHMARKS_INSERT_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>
#include <deque>
#include "Timer.h"
#include "Product.h"

namespace Insert_sequence {

    void containers_insert_begin() {
        std::size_t size = 10000000;
        Product product;
        Product prod_ins(10,101.0);
        std::vector<Product> vec(size, product);
        std::deque<Product> deq(size,product);
        std::list<Product> lst(size, product);
        std::forward_list<Product> f_lst(size, product);
        std::cout << "Insert at the BEGINNING" << std::endl;

        {
            Timer timer;
            vec.insert(vec.begin(), prod_ins);
            std::cout << "vector time_reallocate: ";
        }

        {
            Timer timer;
            vec.insert(vec.begin(), prod_ins);
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.push_front(prod_ins);
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            lst.push_front(prod_ins);
            std::cout << "list time: ";
        }

        {
            Timer timer;
            f_lst.push_front(prod_ins);
            std::cout << "forward_list time: ";
        }

    }

    void containers_insert_end() {
        std::size_t size = 10000000;
        Product product;
        Product prod_ins(10,101.0);
        std::vector<Product> vec(size, product);
        std::deque<Product> deq(size,product);
        std::list<Product> lst(size, product);
        std::forward_list<Product> f_lst(size, product);
        std::cout << "Insert at the END" << std::endl;

        // reallocate
        {
            Timer timer;
            vec.push_back(prod_ins);
            std::cout << "vector time_reallocate: ";
        }

        {
            Timer timer;
            vec.push_back(prod_ins);
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.push_back(prod_ins);
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            lst.push_back(prod_ins);
            std::cout << "list time: ";
        }

        {
            Timer timer;
            auto before_end = std::next(f_lst.begin(), std::distance(f_lst.begin(), f_lst.end()) - 1);
            f_lst.insert_after(before_end, prod_ins);
            std::cout << "forward_list time: ";
        }
    }

    void containers_insert_middle() {
        std::size_t size = 10000000;
        Product product;
        Product prod_ins(10,101.0);
        std::vector<Product> vec(size, product);
        std::deque<Product> deq(size,product);
        std::list<Product> lst(size, product);
        std::forward_list<Product> f_lst(size, product);
        std::cout << "Insert at the MIDDLE" << std::endl;

        // reallocate
        {
            Timer timer;
            vec.insert(vec.begin() + vec.size() / 2, prod_ins);
            std::cout << "vector time_reallocate: ";
        }

        {
            Timer timer;
            vec.insert(vec.begin() + vec.size() / 2, prod_ins);
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            deq.insert(deq.begin() + deq.size() / 2, prod_ins);
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            auto it = lst.begin();
            std::advance(it, lst.size() / 2);
            lst.insert(it, prod_ins);
            std::cout << "list time: ";
        }

        {
            Timer timer;
            auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
            f_lst.insert_after(before_middle, prod_ins);
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
