#ifndef HUMAN_B_HPP_
#define HUMAN_B_HPP_

#include <iostream>
#include "Weapon.hpp"
class HumanB {
 private:
	std::string name_;
	Weapon *weapon_;
 public:
	HumanB(std::string name);
	
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
