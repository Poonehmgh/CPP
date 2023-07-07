#include"../inc/Zombie.hpp"

Zombie::Zombie(): _name_("default")
{
	std::cout << "Default constructor called.\n";
}

Zombie::Zombie(std::string str): _name_(str)
{
	std::cout << _name_ << " Constructor called.\n";
}

void    Zombie::announce (void)
{
    std::cout << _name_<< ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout << _name_ << ": Byyyyyye\n";
}