#include"../inc/ClapTrap.hpp"
#include <iostream>

int main (void) 
{
    ClapTrap sara("Sara");
    ClapTrap tara("Tara");
    sara.setAttackDamage(1);
    tara.setAttackDamage(4);
    sara.attack("Tara");
    tara.takeDamage(sara.getAttackDamage());
    for (int i = 0; i < 5; i++)
    {
        sara.attack("Tara");
        tara.takeDamage(sara.getAttackDamage());
    }
    for (int i = 0; i < 3; i++)
    {
        tara.attack("Sara");
        sara.takeDamage(tara.getAttackDamage());
    }
    sara.beRepaired(5);
}