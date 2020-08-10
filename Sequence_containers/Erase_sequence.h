
#ifndef BENCHMARKS_ERASE_H
#define BENCHMARKS_ERASE_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>
#include <deque>
#include "Timer.h"

namespace Erase_sequence {

    std::size_t size = 100000;

    void containers_erase_begin() {
        Product product;
        std::vector<Product> vec(size, product);
        std::deque<Product> deq(size,product);
        std::list<Product> lst(size, product);
        std::forward_list<Product> f_lst(size, product);
        std::cout << "Erase at the BEGINNING" << std::endl;

        {
            Timer timer;
            while(!vec.empty())
            {
                vec.erase(vec.begin());
            }

            std::cout << "vector time: ";
        }

        {
            Timer timer;
            while(!deq.empty())
            {
                deq.pop_front();
            }
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            while(!lst.empty())
            {
                lst.pop_front();
            }
            std::cout << "list time: ";
        }

        {
            Timer timer;
            while(!f_lst.empty())
            {
                f_lst.pop_front();
            }
            std::cout << "forward_list time: ";
        }

    }

    void containers_erase_end() {
        Product product;
        std::vector<Product> vec(size, product);
        std::deque<Product> deq(size,product);
        std::list<Product> lst(size, product);
        std::forward_list<Product> f_lst(size, product);
        std::cout << "Erase at the END" << std::endl;

        {
            Timer timer;
            while(!vec.empty())
            {
                vec.pop_back();
            }
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            while(!deq.empty())
            {
                deq.pop_back();
            }
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            while(!lst.empty())
            {
                lst.pop_back();
            }
            std::cout << "list time: ";
        }

        {
            Timer timer;
            f_lst.reverse();
            while(!f_lst.empty())
            {
                f_lst.pop_front();
            }
            std::cout << "forward_list time: ";
        }

    }

    void containers_erase_middle() {
        Product product;
        std::vector<Product> vec(size, product);
        std::deque<Product> deq(size,product);
        std::list<Product> lst(size, product);
        std::forward_list<Product> f_lst(size, product);
        std::cout << "Erase at the MIDDLE" << std::endl;

        {
            Timer timer;
            while(!vec.empty())
            {
                auto middle = vec.begin()+vec.size()/2;
                vec.erase(middle);
            }
            std::cout << "vector time: ";
        }

        {
            Timer timer;
            while(!deq.empty())
            {
                auto middle = deq.begin()+deq.size()/2;
                deq.erase(middle);
            }
            std::cout << "deque time: ";
        }

        {
            Timer timer;
            while(!lst.empty())
            {
                auto middle = lst.begin();
                std::advance(middle, lst.size() / 2);
                lst.erase(middle);
            }
            std::cout << "list time: ";
        }

        {
            Timer timer;
            while(!f_lst.empty())
            {
                int distance = std::distance(f_lst.begin(), f_lst.end()) / 2;
                if (distance > 0) {
                    auto before_middle = f_lst.begin();
                    std::advance(before_middle, --distance);
                    f_lst.erase_after(before_middle);
                } else {
                    f_lst.pop_front();
                }
            }
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
