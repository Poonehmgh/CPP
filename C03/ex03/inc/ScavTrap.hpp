#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include"ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(ScavTrap &src);
        ScavTrap    &operator=(ScavTrap const &src);
        void    attack(std::string name);
        void    guardGate();
};

#endif