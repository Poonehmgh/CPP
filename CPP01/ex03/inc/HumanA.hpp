#ifndef HUMANA_H
# define    HUMANA_H
#include"Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weap);
        void    attack() const;
    private:
        Weapon &_weapon_;
        std::string _name_;
};

#endif