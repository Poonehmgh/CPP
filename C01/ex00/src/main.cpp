#include"../inc/Zombie.hpp"

int main()
{
    std::string prompt;
    Zombie  *ZombiePointer;

    std::cout<<"Zombie name?\n";
    getline(std::cin, prompt);
    std::cout<<"Zombie on the Stack:\n";
    randomChump(prompt);
    std::cout<<"Zombie name?\n";
    getline(std::cin, prompt);
    std::cout<<"Zombie on Heap:\n";
    ZombiePointer = newZombie(prompt);
    std::cout<<"Zombie on Heap is deleted:\n";
    delete ZombiePointer;
    return (0);
}