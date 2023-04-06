#ifndef HUMANA_H
# define    HUMANA_H
#include"Weapon.hpp"

class HumanA
{
    public:
    HumanA(std::string name, Weapon &weap);
    Weapon  get_weapon(void);
    void    attack();
    private:
    Weapon &_weapon;
    std::string _name;
};

#endif