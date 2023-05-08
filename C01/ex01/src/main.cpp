#include"../inc/Zombie.hpp"

int main(int argc, char **argv)
{
    Zombie		*Zombie_ptr;

	if (argc == 3)
	{
		int			N = atoi(argv[1]);
		std::string	name = argv[2];
		Zombie_ptr = zombieHorde(N, name);
		std::cout << "Created " << N << " Zombies.\n";
		delete[] Zombie_ptr;
	}
    else
        std::cout << "enter correct arguments: 1. number of zombies 2. zombie name.\n";
	return (0);
}