#ifndef Temps_h
# define Temps_h
# include<iostream>
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

template<typename T>
void    swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T const a, T const b)
{
    if (a >= b)
        return (b);
    return (a);
}

template<typename T>
T max(T const a, T const b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif
