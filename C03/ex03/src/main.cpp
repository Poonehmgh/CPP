#include"../inc/ClapTrap.hpp"
#include"../inc/FragTrap.hpp"
#include"../inc/DiamondTrap.hpp"

#include <iostream>

int main (void) 
{
    DiamondTrap rick("Rick");
    rick.whoAmI();
    ClapTrap    old_dude("Old dude");
    ScavTrap    morty("Morty");
    std::cout << " we have 3 fighters here:" << rick.getName() << " and " << morty.getName() << " and " << old_dude.getName() << "\n";
    std::cout << "they have different attack damage powers:" << rick.getAttackDamage() << " and " << morty.getAttackDamage() <<" and "<< old_dude.getAttackDamage() << "\n";
    
    rick.attack("Old dude");
    rick.attack_ft("Old dude");
    rick.attack_st("Old dude");
    old_dude.takeDamage(rick.getAttackDamage());
    morty.attack_st("Rick");
    rick.takeDamage(morty.getAttackDamage());
    rick.guardGate();
    morty.guardGate();
    rick.highFivesGuys();
    }