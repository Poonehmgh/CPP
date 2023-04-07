#include"../inc/Weapon.hpp"

Weapon::Weapon(std::string newType): _type(newType){}

void Weapon::setType(std::string newType)
{
    _type = newType;
}

std::string const &Weapon::getType(void) const
{
    std::string const &tmp = _type;
    return(tmp);
}