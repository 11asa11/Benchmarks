
#ifndef BENCHMARKS_ERASE_H
#define BENCHMARKS_ERASE_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>

namespace Erase {

    void containers_erase_begin() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Erase at the BEGINNING" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        vec.erase(vec.begin());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector = end - start;

        start = std::chrono::high_resolution_clock::now();
        lst.pop_front();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_list = end - start;

        start = std::chrono::high_resolution_clock::now();
        f_lst.pop_front();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_f_list = end - start;

        std::cout << "vector time: " << duration_vector.count() << std::endl;
        std::cout << "list time: " << duration_list.count() << std::endl;
        std::cout << "forward_list time: " << duration_f_list.count() << std::endl;
    }

    void containers_erase_end() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Erase at the END" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        vec.pop_back();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector = end - start;

        start = std::chrono::high_resolution_clock::now();
        lst.pop_back();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_list = end - start;

        start = std::chrono::high_resolution_clock::now();
        auto before_end = std::next(f_lst.begin(), std::distance(f_lst.begin(), f_lst.end()) - 2);
        f_lst.erase_after(before_end);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_f_list = end - start;

        std::cout << "vector time: " << duration_vector.count() << std::endl;
        std::cout << "list time: " << duration_list.count() << std::endl;
        std::cout << "forward_list time: " << duration_f_list.count() << std::endl;
    }

    void containers_erase_middle() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Erase at the MIDDLE" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        vec.erase(vec.begin() + vec.size() / 2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector = end - start;

        start = std::chrono::high_resolution_clock::now();
        auto it = lst.begin();
        std::advance(it, lst.size() / 2);
        lst.erase(it);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_list = end - start;

        start = std::chrono::high_resolution_clock::now();
        auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
        f_lst.erase_after(before_middle);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_f_list = end - start;

        std::cout << "vector time: " << duration_vector.count() << std::endl;
        std::cout << "list time: " << duration_list.count() << std::endl;
        std::cout << "forward_list time: " << duration_f_list.count() << std::endl;
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
