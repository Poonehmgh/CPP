#include"../inc/Zombie.hpp"


Zombie::Zombie(std::string str): name(str)
{
    announce();
}


void    Zombie::announce (void)
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout<<this->name<<": Byyyyyye\n";
}