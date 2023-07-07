#ifndef HUMANB_H
# define    HUMANB_H
#include"Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        void    attack() const;
        void set_weapon(std::string weapon);
        Weapon *get_weapon(void) const;
    private:
        Weapon *_weapon_;
        std::string _name_;
};

#endif