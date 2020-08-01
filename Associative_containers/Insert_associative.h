
#ifndef BENCHMARKS_INSERT_ASSOCIATIVE_H
#define BENCHMARKS_INSERT_ASSOCIATIVE_H

#include "Timer.h"
#include <set>
#include <map>
#include <chrono>
#include "Product.h"

namespace Insert_associative {

    void containers_insert() {
        std::size_t size = 10000000;
        Product product;
        Product prod_ins(10,101.0);

        std::set<Product> _set;
        std::multiset<Product> _multiset;

        std::map<int,Product> _map;
        std::multimap<int,Product> _multimap;
        std::cout << "Insert" << std::endl;


        for(std::size_t i = 1; i <= size; i++) {
            _set.emplace(i,i);
            _map.emplace(i,product);
            _multiset.emplace(i,i);
            _multimap.emplace(i,product);
        }

        std::size_t key = size + 10;

        {
            Timer timer;
            _set.emplace(key,key);
            std::cout << "set time: ";
        }

        {
            Timer timer;
            _multiset.emplace(key,key);
            std::cout << "multiset time: ";
        }

        {
            Timer timer;
            _map.emplace(key,prod_ins);
            std::cout << "map time: ";
        }

        {
            Timer timer;
            _multimap.emplace(key,prod_ins);
            std::cout << "multimap time: ";
        }

    }


    void start_insert_test() {
        containers_insert();
        std::cout << std::endl;
    }
}

#endif //BENCHMARKS_INSERT_ASSOCIATIVE_H
