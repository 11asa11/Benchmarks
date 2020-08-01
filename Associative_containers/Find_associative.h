
#ifndef BENCHMARKS_FIND_ASSOCIATIVE_H
#define BENCHMARKS_FIND_ASSOCIATIVE_H

#include "Timer.h"
#include <set>
#include <map>
#include <chrono>
#include "Product.h"

namespace Find_associative {

    void containers_find() {
        std::size_t size = 10000000;
        Product product;
        Product prod_ins(10,101.0);

        std::set<Product> _set;
        std::multiset<Product> _multiset;

        std::map<int,Product> _map;
        std::multimap<int,Product> _multimap;
        std::cout << "Find" << std::endl;



        for(std::size_t i = 1; i <= size; i++) {
            _set.emplace(i,i);
            _map.emplace(i,product);
            _multiset.emplace(i,i);
            _multimap.emplace(i,product);
        }

        std::size_t key = size / 2;

        {
            Timer timer;
            _set.find(Product(key,key));
            std::cout << "set time: ";
        }

        {
            Timer timer;
            _multiset.find(Product(key,key));
            std::cout << "multiset time: ";
        }

        {
            Timer timer;
            _map.find(key);
            std::cout << "map time: ";
        }

        {
            Timer timer;
            _multimap.find(key);
            std::cout << "multimap time: ";
        }

    }


    void start_find_test() {
        containers_find();
        std::cout << std::endl;
    }
}

#endif //BENCHMARKS_FIND_ASSOCIATIVE_H
