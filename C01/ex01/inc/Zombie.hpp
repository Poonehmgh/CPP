#ifndef ZOMBIE_H
# define ZOMBIE_H
#include<iostream>

class Zombie
{
    public:
    void    announce(void);
    void    initialize(std::string str);
    ~Zombie();
    private:
    std::string name;
};

Zombie  *zombieHorde(int N, std::string name);


#endif