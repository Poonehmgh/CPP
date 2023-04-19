#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#include<iostream>

class ClapTrap
{
    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &src);
    ~ClapTrap();
    ClapTrap    &operator=(ClapTrap const &src);
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void setAttackDamage(int damage);
    void setName(std::string name);
    void setHitPoints(int hitp);
    void setEnergyPoints(int energyp);
    int  getAttackDamage() const;
    int  getHitPoints() const;
    int  getEnergyPoints() const;
    std::string getName(void) const;
    protected:
    std::string _name_;
    int _hitPoints_;
    int _energyPoints_;
    int _attackDamage_;
};

#endif