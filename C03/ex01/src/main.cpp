#include"../inc/ClapTrap.hpp"
#include"../inc/ScavTrap.hpp"
#include <iostream>

int main (void) 
{
    ScavTrap    siri("Siri");
    ScavTrap    bixbi("Bixbi");
    siri.attack_st("Bixbi");
    bixbi.takeDamage(siri.getAttackDamage());
    bixbi.beRepaired(2);
    bixbi.setAttackDamage(5);
    bixbi.attack_st(siri.getName());
    siri.takeDamage(bixbi.getAttackDamage());
}