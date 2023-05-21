#ifndef MutantStack_H
#define MutantStack_H
#include <iostream>
# define  GREEN "\x1B[1;32m"
# define YELLOW "\x1B[1;33m"
# define  RESET "\x1B[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"
#include <algorithm>
#include <exception>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack const &src);
        MutantStack    &operator=(MutantStack const &src);
        void    addNumber(int n);
        class EmptyContainer: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("Container is empty.");
            }
        };
            class ExceedSize: public std::exception
        {
            virtual const char *what() const throw()
            {
                return("It is exceeding the max number of elements acceptable.");
            }
        };
        typedef typename std::stack<T>::container_type::iterator    iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator    reverse_iterator;
        iterator   begin();    // same as this: typename std::stack<T>::container_type::iterator   begin();
        iterator end();        // same as this: typename std::stack<T>::container_type::iterator   end();
        reverse_iterator   rbegin();
        reverse_iterator   rend();
};

template<typename T> 
MutantStack<T>::MutantStack()
{
}

template<typename T> 
MutantStack<T>::~MutantStack(){}

template<typename T> 
MutantStack<T>::MutantStack(MutantStack const &src)
{
    *this = src;
}
template<typename T> 
MutantStack<T>    &MutantStack<T>::operator=(MutantStack const &src)//chn
{
    // _vec_ = src._vec_;
    (void)src;
    return(*this);
}

template<typename T>
typename std::stack<T>::container_type::iterator    MutantStack<T>::begin() // why i cannot say: iterator_  MutantStack<T>::begin(){} ?
{
    return(this->c.begin());
}

template<typename T>
typename std::stack<T>::container_type::iterator    MutantStack<T>::end() 
{
    return(this->c.end()); 
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator    MutantStack<T>::rend() 
{
    return(this->c.rend()); 
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator    MutantStack<T>::rbegin() 
{
    return(this->c.rbegin()); 
}
#endif
