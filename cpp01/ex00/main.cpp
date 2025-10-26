# include "Zombie.hpp"

int	main()
{
	Zombie	*heapZombie;

	heapZombie = newZombie("Zi");
	heapZombie->announce();
	delete heapZombie; 

	randomChump("Abdo");
	return (0);
}