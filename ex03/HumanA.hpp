#ifndef HUMAN_A_HPP_
#define HUMAN_A_HPP_

#include <iostream>
#include "Weapon.hpp"
class HumanA {
 private:
	std::string name_;
	Weapon &weapon_;
 public:
	HumanA(std::string name, Weapon &weapon);
	
	void attack();
};

#endif
