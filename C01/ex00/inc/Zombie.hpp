#ifndef ZOMBIE_H
# define ZOMBIE_H
#include<iostream>

class Zombie
{
    public:
    void    announce(void);
    Zombie(std::string str);
    ~Zombie();
    private:
    std::string name;
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string nz_name);

#endif