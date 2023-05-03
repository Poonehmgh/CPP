#ifndef Iter_h
# define Iter_h
# include<iostream>
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

template<typename A, size_t B,  void(*f)(A)>
void    iter(A *array, size_t l)
{
    for (size_t i = 0; i < l; i++)
        f(array[i]);
    
}

template<typename A>
void print(A element)
{
    std::cout << BLUE << element << RESET << "\n";
}


#endif
