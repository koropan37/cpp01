#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie {
 private:
	std::string name;

 public:
	Zombie(std::string newname);
	Zombie();
	~Zombie();

	void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
