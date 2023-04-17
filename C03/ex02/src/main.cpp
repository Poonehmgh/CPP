#include"../inc/ClapTrap.hpp"
#include"../inc/FragTrap.hpp"
#include <iostream>

int main (void) 
{
    FragTrap    siri("Siri");
    FragTrap    bixbi("Bixbi");
    siri.attack_ft("Bixbi");
    bixbi.takeDamage(siri.getAttackDamage());
    bixbi.beRepaired(2);
    bixbi.setAttackDamage(5);
    bixbi.attack_ft(siri.getName());
    siri.takeDamage(bixbi.getAttackDamage());
    bixbi.highFivesGuys();
}