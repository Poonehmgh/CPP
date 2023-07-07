#ifndef ZOMBIE_H
# define ZOMBIE_H
#include<iostream>

class Zombie
{
    public:
    Zombie();
    Zombie(std::string str);
    ~Zombie();
    void    announce(void);
    private:
    std::string _name_;
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string nz_name);

#endif