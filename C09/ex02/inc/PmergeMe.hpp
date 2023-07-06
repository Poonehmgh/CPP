#ifndef PMERGEME_H
#define PMERGEME_H
#include<iostream>
#define  GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define  RESET "\x1B[0;37m"
#define BLUE  "\033[36m"
#define RED    "\033[0;31m"
#include <algorithm>
#include <exception>
#include<fstream>
#include<sstream>
#include<time.h>
#include<vector>

// std::vector<int> merge(std::vector<int> one, std::vector<int> two);
// std::vector<int> merge_sort(std::vector<int> vect_arr);
// std::vector<int> insertion_sort(std::vector<int> arr);

// template<typename T>
// T ford_johnson_merge_insert(T arr)
// {
//     int size = arr.size();

//     if (size <= 1)
//         return arr;

//     T sorted;

//     for (int i = 0; i < size; i += 10) {
//         int end = std::min(i + 10, size);
//         T chunk(T.begin() + i, T.begin() + end);
//         chunk = insertion_sort(chunk);
//         sorted = merge(sorted, chunk);
//     }

//     return sorted;
// }



class mi_sort
{
    std::vector<int> arr;

};

#endif
