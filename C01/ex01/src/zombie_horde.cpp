#include"../inc/Zombie.hpp"
#include<string>

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *horde = new Zombie[N];
    for(int i = 0; i < N; i++)
        horde[i].initialize(name);
    return(horde);
}