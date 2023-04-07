#include"../inc/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){}

void HumanB::attack() const
{
    if (_weapon) //I put this guard here in case _weapon is null, but I couldnt test it. when I initialized weapon with NULL, it seg faulted. why?
        std::cout<<_name<<" attacks with their "<<(*_weapon).getType()<<std::endl;
    else
        std::cout<<_name<<" has no weapon to attack "<<std::endl;
}

void    HumanB::set_weapon(std::string weapon)
{
    _weapon = new Weapon(weapon);
}

Weapon *HumanB::get_weapon(void) const
{
    return(_weapon);
}