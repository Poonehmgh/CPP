#include "../inc/rpn.hpp"
#include<iostream>
#include<cctype>


int main(int argc, char **argv) 
{
    try
    {
        if (argc != 2)
            throw(wrongInput());
        int result = calculator(argv);
        std::cout << result << std::endl;
    }catch(std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}
