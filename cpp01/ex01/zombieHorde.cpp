#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
	{
		std::cout << "Enter a positive Number N " << std::endl;
		return (0);
	}

    Zombie *h = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        h[i].set_name(name);
        h[i].announce();
    }

    return h;
}