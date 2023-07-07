#ifndef ZOMBIE_H
# define ZOMBIE_H
#include<iostream>

class Zombie
{
    public:
    void    announce(void);
    void    setZombie(std::string str);
    Zombie(std::string name);
    Zombie();
    ~Zombie();
    private:
    std::string _name_;
};

Zombie  *zombieHorde(int N, std::string name);


#endif