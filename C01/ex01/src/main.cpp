#include"../inc/Zombie.hpp"

int main()
{
    std::string prompt;
    std::string n;
    int         num;
    Zombie  *ZombiePointer;

    std::cout<<"whats the name of zombies?\n";
    getline(std::cin, prompt);
    std::cout<<"and how many?\n";
    getline(std::cin, n);
    num = std::stoi(n);
    ZombiePointer = zombieHorde(num, prompt);
    delete[] ZombiePointer;
    return (0);
}