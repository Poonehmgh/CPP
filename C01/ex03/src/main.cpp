#include"../inc/Weapon.hpp"
#include"../inc/HumanA.hpp"
#include"../inc/HumanB.hpp"

int main()
{
    {
    Weapon club("crude spike");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("other type");
    bob.attack();
    }
    {
    Weapon club("crude spike");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("other type");
    bob.attack();
    }
}