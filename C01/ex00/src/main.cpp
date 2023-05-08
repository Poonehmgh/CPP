#include"../inc/Zombie.hpp"

int main()
{
    Zombie	*Zombies[4]; // Double-pointer to Zombie pointer type array.
	int		i = 0;

	std::cout << " allocating space for these ones inside the .newZombie function.\n";
	Zombies[0] = newZombie("Sara"); // Store pointer to first Zombie in [0].
	Zombies[1] = newZombie("Lara");
	Zombies[2] = newZombie("Tara");
	Zombies[3] = NULL;
	while (Zombies[i])
	{
		Zombies[i]->announce();
		std::cout  << "Deleting...\n";
		delete Zombies[i];
		i++;
	}
	i = 0;
	randomChump("Bill");
	randomChump("Gill");
	randomChump("Vill");
    return (0);
}