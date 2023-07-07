#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        ~DiamondTrap();
        DiamondTrap(DiamondTrap &src);
        DiamondTrap &operator=(DiamondTrap &src);
        void    setName(std::string name);
        std::string getName(void) const;
        using FragTrap::attack;
        void    whoAmI();
    private:
        std::string _name_;
};

#endif
