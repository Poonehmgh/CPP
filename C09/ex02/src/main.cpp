#include "../inc/PmergeMe.hpp"

void    input_check(char **argv, int argc)
{
    int i = 1;
    std::string tmp;
    while( i < argc)
    {
        tmp = argv[i];
        for (unsigned int j = 0 ; j < tmp.size(); j++)
            if (!isdigit(tmp.at(j)))
            {
                std::cerr << RED"Error! Only positive integer numbers are acceptable.\n" << RESET;
                exit(1);
            }    
        i++;
    }
    i = 1;
    std::cout << YELLOW"BEFORE : ";
    while(i < argc && i < 5)
    {
        std::cout << YELLOW << argv[i] << "  ";
        i++;
    }
    if (argc >= 5)
        std::cout << " [...]" << RESET << std::endl;
    else
        std::cout << "\n" << RESET;
}

int main(int argc, char **argv) 
{
    input_check(argv, argc);

    clock_t         start;
    clock_t         end;

    int i = 1;

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
