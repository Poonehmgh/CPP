#ifndef FRAGTRAP_H
# define FRAGTRAP_H
#include"ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(FragTrap &src);
    FragTrap    &operator=(FragTrap const &src);
    void    attack_ft(std::string name);
    void highFivesGuys(void);
};
#endif