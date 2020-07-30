
#ifndef BENCHMARKS_INSERT_H
#define BENCHMARKS_INSERT_H

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <chrono>
#include <deque>

namespace Insert {

    void containers_insert_begin() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Insert at the BEGINNING" << std::endl;

        // reallocate
        auto start = std::chrono::high_resolution_clock::now();
        vec.insert(vec.begin(), 9);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector_reallocate = end - start;

        start = std::chrono::high_resolution_clock::now();
        vec.insert(vec.begin(),9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector = end - start;

        start = std::chrono::high_resolution_clock::now();
        deq.push_front(9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_deque = end - start;

        start = std::chrono::high_resolution_clock::now();
        lst.push_front(9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_list = end - start;

        start = std::chrono::high_resolution_clock::now();
        f_lst.push_front(9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_f_list = end - start;

        std::cout << "vector time: " << duration_vector.count() << std::endl;
        std::cout << "vector time_reallocate: " << duration_vector_reallocate.count() << std::endl;
        std::cout << "deque time: "<<duration_deque.count()<< std::endl;
        std::cout << "list time: " << duration_list.count() << std::endl;
        std::cout << "forward_list time: " << duration_f_list.count() << std::endl;
    }

    void containers_insert_end() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Insert at the END" << std::endl;

        // reallocate
        auto start = std::chrono::high_resolution_clock::now();
        vec.push_back(9);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector_reallocate = end - start;

        start = std::chrono::high_resolution_clock::now();
        vec.push_back(9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector = end - start;

        start = std::chrono::high_resolution_clock::now();
        deq.push_back(9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_deque = end - start;

        start = std::chrono::high_resolution_clock::now();
        lst.push_back(9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_list = end - start;

        start = std::chrono::high_resolution_clock::now();
        auto before_end = std::next(f_lst.begin(), std::distance(f_lst.begin(), f_lst.end()) - 1);
        f_lst.insert_after(before_end, 9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_f_list = end - start;

        std::cout << "vector time: " << duration_vector.count() << std::endl;
        std::cout << "vector time_reallocate: " << duration_vector_reallocate.count() << std::endl;
        std::cout << "deque time: "<<duration_deque.count()<< std::endl;
        std::cout << "list time: " << duration_list.count() << std::endl;
        std::cout << "forward_list time: " << duration_f_list.count() << std::endl;
    }

    void containers_insert_middle() {
        std::size_t size = 10000000;
        std::vector<int> vec(size, 1);
        std::deque<int> deq(size,1);
        std::list<int> lst(size, 1);
        std::forward_list<int> f_lst(size, 1);
        std::cout << "Insert at the MIDDLE" << std::endl;

        // reallocate
        auto start = std::chrono::high_resolution_clock::now();
        vec.insert(vec.begin() + vec.size() / 2, 9);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector_reallocate = end - start;

        start = std::chrono::high_resolution_clock::now();
        vec.insert(vec.begin() + vec.size() / 2, 9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_vector = end - start;

        start = std::chrono::high_resolution_clock::now();
        deq.insert(deq.begin() + deq.size() / 2, 9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_deque = end - start;

        start = std::chrono::high_resolution_clock::now();
        auto it = lst.begin();
        std::advance(it, lst.size() / 2);
        lst.insert(it, 9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_list = end - start;

        start = std::chrono::high_resolution_clock::now();
        auto before_middle = std::next(f_lst.begin(), (std::distance(f_lst.begin(), f_lst.end())) / 2);
        f_lst.insert_after(before_middle, 9);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_f_list = end - start;

        std::cout << "vector time: " << duration_vector.count() << std::endl;
        std::cout << "vector time_reallocate: " << duration_vector_reallocate.count() << std::endl;
        std::cout << "deque time: "<<duration_deque.count()<< std::endl;
        std::cout << "list time: " << duration_list.count() << std::endl;
        std::cout << "forward_list time: " << duration_f_list.count() << std::endl;
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
