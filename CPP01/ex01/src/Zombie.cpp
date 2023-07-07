#include"../inc/Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Default constructor is called.\n";
};
Zombie::Zombie(std::string name): _name_(name)
{} 


Zombie::~Zombie()
{
    std::cout<< _name_ <<": Byyyyyye\n";
}

void    Zombie::announce (void)
{
    std::cout<< _name_ <<": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setZombie(std::string str)
{
    _name_ = str;
    announce();
}