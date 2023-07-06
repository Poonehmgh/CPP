#ifndef PMERGEME_H
#define PMERGEME_H
#include<iostream>
#define  GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define  RESET "\x1B[0;37m"
#define BLUE  "\033[36m"
#define RED    "\033[0;31m"
#include <algorithm>
#include<vector>
#include<deque>
#include<ctime>


template<typename T>
T merge(T one, T two)
{
    T three;

    while (one.size() != 0 && two.size() != 0)
    {
        if (one.at(0) > two.at(0))
        {
            three.push_back(two.at(0));
            two.erase(two.begin());
        }
        else
        { 
            three.push_back(one.at(0));
            one.erase(one.begin());
        }
    }
    while (one.size() != 0)
    {
        three.push_back(one.at(0));
        one.erase(one.begin());
    }
    while (two.size() != 0)
    {
        three.push_back(two.at(0));
        two.erase(two.begin());
    }
    return (three);
}


template<typename T>
T merge_sort(T vect_arr)
{
    if (vect_arr.size() == 1)
        return (vect_arr);
    int size = vect_arr.size();
    T   array_one(vect_arr.begin(), vect_arr.begin() + size / 2);
    T   array_two(vect_arr.begin() + size / 2, vect_arr.end());
    array_one = merge_sort(array_one);
    array_two = merge_sort(array_two);

    return(merge(array_one, array_two));
}

template<typename T>
T insertion_sort(T arr)
{
    int size = arr.size();
    int i;
    int j;

    for (i = 1; i < size; i++)
    {
        j = i;
        while (j > 0 && arr.at(j - 1) > arr.at(j))
        {
            int swap = arr.at(j - 1);
            arr.at(j - 1) = arr.at(j);
            arr.at(j) = swap;
            j--;
        }
    }
    return(arr);
}

template<typename T>
T ford_johnson_merge_insert(T arr)
{
    int size = arr.size();

    if (size <= 1)
        return arr;

    T sorted;

    for (int i = 0; i < size; i += 10) {
        int end = std::min(i + 10, size);
        T chunk(arr.begin() + i, arr.begin() + end);
        chunk = insertion_sort(chunk);
        sorted = merge(sorted, chunk);
    }

    return sorted;
}


template<typename T>
void print_data(T &a, double duration_deque, double duration_vect)
{
    int j = 0;
    std::cout << YELLOW << "AFTER : "; 
    for (typename T::iterator i = a.begin(); (i != a.end() && j < 4); i++)
    {
        std::cout << *i << "  ";
        j++;
    }
    if (a.size() >= 5)
        std::cout << " [...]" << RESET << std::endl;
    else
        std::cout << "\n" << RESET;
    
    std::cout << "Time to process a range of " << a.size() << " elements with std::deque "RED << duration_deque * 1e3 << " ms "RESET << std::endl; 
    std::cout << "Time to process a range of " << a.size() << " elements with std::vector "GREEN << duration_vect * 1e3 << " ms "RESET << std::endl;
}

#endif
