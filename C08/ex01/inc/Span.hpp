#ifndef Span_H
#define Span_H
#include<iostream>
# define  GREEN "\x1B[1;32m"
# define YELLOW "\x1B[1;33m"
# define  RESET "\x1B[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"
#include <algorithm>
#include <exception>
#include<vector>


class Span
{
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(Span const &src);
        Span    &operator=(Span const &src);
        void    addNumber(int n);
        void    fillRandomNumber();
        int     shortestSpan();
        int     longestSpan();
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
        static  int random_num();
        void print_vector();
    private:
        std::vector<int>    _vec_;
        unsigned int        _size_;
        unsigned int                 _index_;
};


#endif
