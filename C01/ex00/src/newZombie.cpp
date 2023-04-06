#include"../inc/Zombie.hpp"

Zombie  *newZombie(std::string nz_name)
{
    Zombie *NZ = new Zombie(nz_name);
    return (NZ);
}