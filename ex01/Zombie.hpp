#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie {
 private:
	std::string name;

 public:
 	Zombie(const std::string &newname);
	Zombie();
	~Zombie();

	void set_name(std::string name);

	void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
