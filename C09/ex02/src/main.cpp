#include "../inc/PmergeMe.hpp"


int main(int argc, char **argv) 
{
    input_check(argv, argc);

    clock_t         start;
    clock_t         end;

    int i = 1;
    /*      processing with vector      */
    std::vector<int> vect;
    start = clock();
    while (i < argc)
    {
        vect.push_back(atoi(argv[i]));
        i++;
    }
    vect = ford_johnson_merge_insert(vect);
    end = clock();
    double duration_vect = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    i = 1;
    /*      processing with deque       */
    std::deque<int>  deque;
    start = clock();
    while (i < argc)
    {
        deque.push_back(atoi(argv[i]));
        i++;
    }
    deque = ford_johnson_merge_insert(deque);
    end = clock();
    double duration_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    
    print_data(vect, duration_deque, duration_vect);
    }
