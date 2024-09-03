#include "Zombie.hpp"

int main()
{
	int N = 3;
	Zombie* horde = zombieHorde(N, "ZombieHorde");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}