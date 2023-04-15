#include"ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap(ScavTrap &src);
    ScavTrap    &operator=(ScavTrap const &src);
    void    attack_st(std::string name);
    void    guardGate();
};