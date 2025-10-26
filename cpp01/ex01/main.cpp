#include "Zombie.hpp"

int	main()
{
	int	N =  2;

	Zombie	*horde = zombieHorde(N, "lQirdi");

	delete[] horde;
	return (0);
}