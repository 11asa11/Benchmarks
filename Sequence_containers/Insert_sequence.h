
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

    std::size_t size = 100000;

    void containers_insert_begin() {
        Product product;
        Product prod_ins(10,101.0);
        std::vector<Product> vec;
        std::deque<Product> deq;
        std::list<Product> lst;
        std::forward_list<Product> f_lst;
        std::cout << "Insert at the BEGINNING" << std::endl;

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                vec.insert(vec.begin(),product);
            }
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
               deq.push_front(product);
            }
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                lst.push_front(product);
            }
            std::cout << "list time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                f_lst.push_front(product);
            }
            std::cout << "forward_list time: ";
        }

    }

    void containers_insert_end() {
        Product product;
        Product prod_ins(10,101.0);
        std::vector<Product> vec;
        std::deque<Product> deq;
        std::list<Product> lst;
        std::forward_list<Product> f_lst;
        std::cout << "Insert at the END" << std::endl;

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                vec.push_back(product);
            }
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                deq.push_back(product);
            }
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                lst.push_back(product);
            }
            std::cout << "list time: ";
        }

        {
            Timer timer;
            f_lst.push_front(product);
            for(std::size_t i = 0; i < size; i++)
            {
                auto before_end = std::next(f_lst.begin(), std::distance(f_lst.begin(), f_lst.end()) - 1);
                f_lst.insert_after(before_end, product);
            }
            std::cout << "forward_list time: ";
        }
    }

    void containers_insert_middle() {
        Product product;
        Product prod_ins(10,101.0);
        std::vector<Product> vec;
        std::deque<Product> deq;
        std::list<Product> lst;
        std::forward_list<Product> f_lst;
        std::cout << "Insert at the MIDDLE" << std::endl;

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                vec.insert(vec.begin() + vec.size() / 2, product);
            }
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                deq.insert(deq.begin() + deq.size() / 2, product);
            }
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                auto it = lst.begin();
                std::advance(it, lst.size() / 2);
                lst.insert(it, product);
            }
            std::cout << "list time: ";
        }

        {
            Timer timer;
            f_lst.push_front(product);
            for(std::size_t i = 0; i < size; i++)
            {
                auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
                f_lst.insert_after(before_middle, product);
            }
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
