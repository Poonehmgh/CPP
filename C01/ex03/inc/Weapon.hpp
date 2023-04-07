#ifndef WEAPON_H
# define WEAPON_H
#include<iostream>

class Weapon
{
    public:
    Weapon(std::string newType);
    void    setType(std::string newType);
    std::string const &getType(void) const;
    private:
    std::string _type;
};


#endif