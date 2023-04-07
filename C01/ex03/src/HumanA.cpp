#include"../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &x): _weapon(x), _name(name){}

void HumanA::attack() const
{
    std::cout<<_name<<" attacks with their "<<_weapon.getType()<<std::endl;
}
