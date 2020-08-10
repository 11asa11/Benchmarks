
#ifndef BENCHMARKS_FIND_UNORDERED_H
#define BENCHMARKS_FIND_UNORDERED_H

#include "Timer.h"
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include "Product.h"

namespace Find_unordered {

    std::size_t size = 100000;

    void containers_find() {
        Product product;
        Product prod_ins(10,101.0);

        std::unordered_set<Product> un_set;
        std::unordered_multiset<Product> un_multiset;

        std::unordered_map<int,Product> un_map;
        std::unordered_multimap<int,Product> un_multimap;
        std::cout << "Find" << std::endl;


        for(std::size_t i = 1; i <= size; i++) {
            un_set.emplace(i,i);
            un_map.emplace(i,product);
            un_multiset.emplace(i,i);
            un_multimap.emplace(i,product);
        }

        std::size_t key = size / 2;

        {
            std::cout << "unordered_set time: "<<std::endl;
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                un_set.find(Product(i,i));
            }
            std::cout << "unordered_set time: ";
        }
        un_set.clear();

        {
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                un_multiset.find(Product(i,i));
            }
            std::cout << "unordered_multiset time: ";
        }
        un_multiset.clear();

        {
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                un_map.find(i);
            }
            std::cout << "unordered_map time: ";
        }
        un_map.clear();

        {
            Timer timer;
            for(std::size_t i = 1; i <= size; i++) {
                un_multimap.find(i);
            }
            std::cout << "unordered_multimap time: ";
        }
        un_multimap.clear();

    }


    void start_find_test() {
        containers_find();
        std::cout << std::endl;
    }
}

#endif //BENCHMARKS_FIND_UNORDERED_H
