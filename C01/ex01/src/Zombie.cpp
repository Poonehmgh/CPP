#include"../inc/Zombie.hpp"


void    Zombie::announce (void)
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout<<this->name<<": Byyyyyye\n";
}

void    Zombie::initialize(std::string str)
{
    name = str;
    announce();
}