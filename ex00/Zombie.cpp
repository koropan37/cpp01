#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &newname) :name(newname) {
	std::cout << "I'm " << name << std::endl;
}

Zombie::Zombie() :name("mob") {
	std::cout << "I'm " << name << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << name << ": What am I? Human or ..." << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}
