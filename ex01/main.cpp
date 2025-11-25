#include "Zombie.hpp"
#include <iostream>

int main(void) {

	int N;
	Zombie *zombies;

	{
		N = 3;
		zombies = zombieHorde(N, "mob");
		for (int i = 0; i < N; ++i)
			zombies[i].announce();
		delete[] zombies;
	}
	{
		N = 0;
		zombies = zombieHorde(N, "zero");
		for (int i = 0; i < N; ++i)
			zombies[i].announce();
		delete[] zombies;
	}
	{
		N = -1;
		zombies = zombieHorde(N, "zero");
		for (int i = 0; i < N; ++i)
			zombies[i].announce();
		delete[] zombies;
	}
}
//delete[] NULLは許容されていて安全(何もしない)
//new [0]は実行依存で必ずdelete[]の必要がある
