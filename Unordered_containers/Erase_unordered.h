
#ifndef BENCHMARKS_ERASE_UNORDERED_H
#define BENCHMARKS_ERASE_UNORDERED_H

#include "Timer.h"
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include "Product.h"

namespace Erase_unordered {

    void containers_erase() {
        std::size_t size = 10000000;
        Product product;
        Product prod_ins(10,101.0);

        std::unordered_set<Product> un_set;
        std::unordered_multiset<Product> un_multiset;

        std::unordered_map<int,Product> un_map;
        std::unordered_multimap<int,Product> un_multimap;
        std::cout << "Erase" << std::endl;


        for(std::size_t i = 1; i <= size; i++) {
            un_set.emplace(i,i);
            un_map.emplace(i,product);
            un_multiset.emplace(i,i);
            un_multimap.emplace(i,product);
        }

        std::size_t key = size / 2;

        {
            Timer timer;
            un_set.erase(Product(key,key));
            std::cout << "unordered_set time: ";
        }
        un_set.clear();

        {
            Timer timer;
            un_multiset.erase(Product(key,key));
            std::cout << "unordered_multiset time: ";
        }
        un_multiset.clear();

        {
            Timer timer;
            un_map.erase(key);
            std::cout << "unordered_map time: ";
        }
        un_map.clear();

        {
            Timer timer;
            un_multimap.erase(key);
            std::cout << "unordered_multimap time: ";
        }
        un_multimap.clear();

    }

    void start_erase_test() {
        containers_erase();
        std::cout << std::endl;
    }
}

#endif //BENCHMARKS_ERASE_UNORDERED_H
