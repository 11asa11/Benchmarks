
#ifndef BENCHMARKS_ERASE_ASSOCIATIVE_H
#define BENCHMARKS_ERASE_ASSOCIATIVE_H

#include "Timer.h"
#include <set>
#include <map>
#include <chrono>
#include "Product.h"

namespace Erase_associative {

    void containers_erase() {
        std::size_t size = 10000000;
        Product product;
        Product prod_ins(10,101.0);

        std::set<Product> _set;
        std::multiset<Product> _multiset;

        std::map<int,Product> _map;
        std::multimap<int,Product> _multimap;
        std::cout << "Erase" << std::endl;


        for(std::size_t i = 1; i <= size; i++) {
            _set.emplace(i,i);
            _map.emplace(i,product);
            _multiset.emplace(i,i);
            _multimap.emplace(i,product);
        }

        std::size_t key = size / 2;

        {
            Timer timer;
            _set.erase(Product(key,key));
            std::cout << "set time: ";
        }

        {
            Timer timer;
            _multiset.erase(Product(key,key));
            std::cout << "multiset time: ";
        }

        {
            Timer timer;
            _map.erase(key);
            std::cout << "map time: ";
        }

        {
            Timer timer;
            _multimap.erase(key);
            std::cout << "multimap time: ";
        }

    }


    void start_erase_test() {
        containers_erase();
        std::cout << std::endl;
    }
}

#endif //BENCHMARKS_ERASE_ASSOCIATIVE_H
