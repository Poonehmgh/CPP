#ifndef rpn_H
#define rpn_H
#include<iostream>
# define  GREEN "\x1B[1;32m"
# define YELLOW "\x1B[1;33m"
# define  RESET "\x1B[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"
#include<exception>
#include<stack>

class wrongInput: public std::exception
{
    virtual const char *what() const throw()
    {
        return("Invalid Input.");
    }
};

class InvalidOperator: public std::exception
{
    virtual const char *what() const throw()
    {
        return("Error! For each two numbers there should be one operator.");
    }
};

class OnlyDigits: public std::exception
{
    virtual const char *what() const throw()
    {
        return("Error! Only digits from 0 to 9 and +-/* are acceptable.\n");
    }
};

#endif
