#include"../inc/FragTrap.hpp"

/*******************************CANONICAL FORM******************/

FragTrap::FragTrap()
{
    _name_ = "Nameless";
    _hitPoints_ = 100;
    _energyPoints_ = 100;
    _attackDamage_ = 30;
    std::cout<< "FragTrap \033[32m " << _name_<< "\033[0m constructor is called.\n";
}

FragTrap::~FragTrap()
{
    std::cout<< "FragTrap \033[32m " << _name_<< "\033[0m destructor is called.\n";
}

FragTrap::FragTrap(FragTrap &src)
{
    *this = src;
    std::cout << "FragTrap \033[32m" << _name_ <<"\033[0m copy constructor called.\n";
}

FragTrap    &FragTrap::operator=(FragTrap const &src)
{
    _name_ = src.getName();
    _energyPoints_ = src.getEnergyPoints();
    _hitPoints_ = src.getHitPoints();
    _attackDamage_ = src.getAttackDamage();
    return(*this);
}

FragTrap::FragTrap(std::string name)
{
    _name_ = name;
    _hitPoints_ = 100;
    _energyPoints_ = 100;
    _attackDamage_ = 30;
    std::cout<< "FragTrap \033[32m " << _name_<< "\033[0m constructor is called.\n";
}

/*****************************************/

void    FragTrap::attack(std::string name)
{
    if (_hitPoints_ && _energyPoints_)
    {
        _energyPoints_ -= 1;
        std::cout<< "FragTrap \033[32m " << _name_<< "\033[0m has attacked " << name << " in an unusual way. hitpoints: " << _hitPoints_ <<"\n";
    }
    else
        std::cout << "FragTrap \033[32m " << _name_<< "\033[0m cannot attack " << name << " because there are no points left. hitpoints: " << _hitPoints_ <<"\n";
}

void FragTrap::highFivesGuys(void)
{
    if (_hitPoints_ && _energyPoints_)
        std::cout << "FragTrap \033[32m" << _name_ << "\033[0m says: high five guys!\n";
    else
        std::cout << "FragTrap has no energy to highfive!\n";
}
