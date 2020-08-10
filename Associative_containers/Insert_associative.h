
#ifndef BENCHMARKS_INSERT_ASSOCIATIVE_H
#define BENCHMARKS_INSERT_ASSOCIATIVE_H

#include "Timer.h"
#include <set>
#include <map>
#include <chrono>
#include "Product.h"

namespace Insert_associative {

    std::size_t size = 100000;

    void containers_insert() {
        Product product;
        Product prod_ins(10,101.0);

        std::set<Product> _set;
        std::multiset<Product> _multiset;

        std::map<int,Product> _map;
        std::multimap<int,Product> _multimap;
        std::cout << "Insert" << std::endl;


        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                _set.emplace(i,i);
            }
            std::cout << "set time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                _multiset.emplace(i,i);
            }
            std::cout << "multiset time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i < size; i++)
            {
                _map.emplace(i,product);
            }
            std::cout << "map time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 0; i <= size; i++)
            {
                _multimap.emplace(i,product);
            }
            std::cout << "multimap time: ";
        }

    }


    void start_insert_test() {
        containers_insert();
        std::cout << std::endl;
    }
}

#endif //BENCHMARKS_INSERT_ASSOCIATIVE_H
