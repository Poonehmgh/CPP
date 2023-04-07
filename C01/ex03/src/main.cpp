#include"../inc/Weapon.hpp"
#include"../inc/HumanA.hpp"
#include"../inc/HumanB.hpp"

int main()
{
    {
    Weapon club("crude spike");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    {
    Weapon club("crude spike");
    HumanB Jo("Jo");
    Jo.set_weapon(club.getType());
    Jo.attack();
    club.setType("some other type of club");    
    Jo.set_weapon(club.getType());
    Jo.attack();
    delete Jo.get_weapon();
    }  
}