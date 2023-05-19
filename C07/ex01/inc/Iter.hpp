#ifndef Iter_h
# define Iter_h
# include<iostream>
# define  GREEN "\x1B[1;32m"
# define YELLOW "\x1B[1;33m"
# define  RESET "\x1B[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

template<typename A>
void    iter(A *array, size_t l, void(*f)(const A &))
{
    for (size_t i = 0; i < l; i++)
        f(array[i]);
    
}

template<typename A>
void print_(A const &element)
{
    std::cout << BLUE << element << RESET << "\n";
}


#endif
