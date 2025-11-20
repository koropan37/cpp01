#include "Zombie.hpp"
#include <iostream>

int main(void) {

	int N;
	Zombie *zombies;

	N = 3;
	zombies = zombieHorde(N, "mob");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;

	N = 0;
	zombies = zombieHorde(N, "zero");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
}
//配列が0のときは new Zombie[0]はコンストラクタを呼ばない
