#include"../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &x): _weapon_(x), _name_(name){}

void HumanA::attack() const
{
    std::cout << _name_ << " attacks with their " << _weapon_.getType() << std::endl;
}
