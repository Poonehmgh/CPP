#ifndef EASYFIND_H
#define EASYFIND_H
#include<iostream>
# define  GREEN "\x1B[1;32m"
# define YELLOW "\x1B[1;33m"
# define  RESET "\x1B[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"
#include <algorithm>
#include <exception>

class NotFound : public std::exception
{
    virtual const char *what() const throw()
    {
        return("not found.");
    }
};

template<typename T>
typename T::iterator easyFind(T cntr, int value)
{
    typename T::iterator it = find(cntr.begin(), cntr.end(), value); //in order for compiler to be able to pars the iterator, we should use the typename keyword again when defining an iterator.
    if (it == cntr.end())
        throw (NotFound()); // i dont know what exactly this is. a clas instance?
    return (it);
}
#endif
