#include "../inc/PmergeMe.hpp"

void    input_check(char **argv, int argc)
{
    if (argc < 2)
    {
        std::cerr << RED"Error! Argument is not provided.\n" << RESET;
        exit(1);   
    }
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

