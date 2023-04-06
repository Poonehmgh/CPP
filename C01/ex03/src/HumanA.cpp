#include"../inc/HumanA.hpp"

void HumanA::attack()
{
    std::cout<<_name<<" attacks with their "<<_weapon.getType()<<std::endl;
}

HumanA::HumanA(std::string name, Weapon &x): _weapon(x), _name(name){}