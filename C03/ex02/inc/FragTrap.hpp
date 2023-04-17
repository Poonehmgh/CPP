#include"ClapTrap.hpp"

class FragTrap: public ClapTrap
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