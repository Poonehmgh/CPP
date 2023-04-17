#include"../inc/ScavTrap.hpp"

/*******************************CANONICAL FORM******************/

ScavTrap::ScavTrap()
{
    _name_ = "Nameless";
    _hitPoints_ = 100;
    _energyPoints_ = 50;
    _attackDamage_ = 20;
    std::cout<< "ScavTrap \033[32m " << _name_<< "\033[0m constructor is called.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout<< "ScavTrap \033[32m " << _name_<< "\033[0m destructor is called.\n";
}

ScavTrap::ScavTrap(ScavTrap &src)
{
    *this = src;
    std::cout<< "ScavTrap \033[32m " << _name_<< "\033[0m copy constructor is called.\n";
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &src)
{
    _name_ = src.getName();
    _hitPoints_ = src.getHitPoints();
    _energyPoints_ = src.getEnergyPoints();
    _attackDamage_ = src.getAttackDamage();
    return(*this);
}

ScavTrap::ScavTrap(std::string name)
{
    _name_ = name;
    _hitPoints_ = 100;
    _energyPoints_ = 50;
    _attackDamage_ = 20;
    std::cout<< "ScavTrap \033[32m " << _name_<< "\033[0m constructor is called.\n";
}

/*****************************************/

void    ScavTrap::guardGate()
{
    if (_hitPoints_ && _energyPoints_)
        std::cout << "The ScavTrap\033[32m "<< _name_ << "\033[0m is in her gate keeper mode.\n";
    else
        std::cout << "The ScavTrap \033[32m " << _name_ << "\033[0m is tired and cant be in keeper mode.\n";

}

void    ScavTrap::attack_st(std::string name)
{
    if (_hitPoints_ && _energyPoints_)
    {
        _energyPoints_ -= 1;
        std::cout<< "ScavTrap \033[32m " << _name_<< "\033[0m has attacked " << name << " in an unusual way. hitpoints: " << _hitPoints_ <<"\n";
    }
    else
        std::cout << "ScavTrap \033[32m " << _name_<< "\033[0m cannot attack " << name << " because there are no points left. hitpoints: " << _hitPoints_ <<"\n";
}
