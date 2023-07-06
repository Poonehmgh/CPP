#include "../inc/PmergeMe.hpp"
#include<vector>
#include<deque>
#include<>


int main(int argc, char **argv) 
{
    std::vector<int> vect;
    std::deque<int>  deque;
    int i = 0;
    while (i < argc)
    {
        vect.push_back(atoi(argv[i]));
        deque.push_back(atoi(argv[i]));
        i++;
    }
    vect = ford_johnson_merge_insert(vect);
    deque = ford_johnson_merge_insert(deque);
    // for(std::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
    //     std::cout << *i << std::endl;
    for(std::deque<int>::iterator ii = deque.begin(); ii != deque.end(); ii++)
        std::cout << GREEN << *ii << RESET << std::endl;
    // mergeInsertionSort(test);
    // if (argc <= 2)
    //     std::cerr << RED"wrong number of arguments!" << std::endl;
    (void)argv;
    (void)argc;
}
