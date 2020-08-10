
#ifndef BENCHMARKS_ERASE_ASSOCIATIVE_H
#define BENCHMARKS_ERASE_ASSOCIATIVE_H

#include "Timer.h"
#include <set>
#include <map>
#include <chrono>
#include "Product.h"

namespace Erase_associative {

    std::size_t size = 100000;

    void containers_erase() {
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


        {
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                _set.erase(Product(i,i));
            }
            std::cout << "set time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                _multiset.erase(Product(i,i));
            }
            std::cout << "multiset time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                _map.erase(i);
            }
            std::cout << "map time: ";
        }

        {
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                _multimap.erase(i);
            }
            std::cout << "multimap time: ";
        }

    }


    void start_erase_test() {
        containers_erase();
        std::cout << std::endl;
    }
}

#endif //BENCHMARKS_ERASE_ASSOCIATIVE_H
