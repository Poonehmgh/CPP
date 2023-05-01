#ifndef abcd_h
# define abcd_h
# include<iostream>
# include <exception>
# define  GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define  RESET "\e[0;37m"
# define BLUE  "\033[36m"
# define RED    "\033[0;31m"

class Base
{
    public:
        virtual ~Base();
};

class A:public Base
{

};

class B:public Base
{

};

class C:public Base
{

};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
