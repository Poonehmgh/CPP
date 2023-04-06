#ifndef HUMANB_H
# define    HUMANB_H
#include"Weapon.hpp"

class HumanB
{
    public:
    HumanB(std::string name);
    void    set_weapon(Weapon X);
    Weapon  get_weapon(void);
    void    attack();
    private:
    Weapon *_weapon;
    std::string _name;
};

#endif