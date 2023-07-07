#ifndef HARL_H
# define    HARL_H
#include<iostream>

class harl
{
    public:
    void complain(std::string level);
    private:
    void _debug();
    void _info();
    void _warning();
    void _error();
};

#endif