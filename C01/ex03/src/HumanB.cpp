#include"../inc/HumanB.hpp"

HumanB::HumanB(std::string name): _name_(name){}

void HumanB::attack() const
{
    if (_weapon_) //I put this guard here in case _weapon is null, but I couldnt test it. when I initialized weapon with NULL, it seg faulted. why?
        std::cout << _name_ << " attacks with their " << (*_weapon_).getType() << std::endl;
    else
        std::cout << _name_ << " has no weapon to attack " << std::endl;
}

void    HumanB::set_weapon(std::string weapon)
{
    _weapon_ = new Weapon(weapon);
}

Weapon *HumanB::get_weapon(void) const
{
    return(_weapon_);
}