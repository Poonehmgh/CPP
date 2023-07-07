#include"../inc/Weapon.hpp"

Weapon::Weapon(std::string newType): _type_(newType){}

void Weapon::setType(std::string newType)
{
    _type_ = newType;
}

std::string const &Weapon::getType(void) const
{
    std::string const &tmp = _type_;
    return(tmp);
}