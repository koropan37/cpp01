#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

void HumanB::setWeapon(Weapon &weapon) { weapon_ = &weapon; }

void HumanB::attack() {
	if(weapon_)
		std::cout << name_ << " attack with " << weapon_->getType() << std::endl;
	else
		std::cout << name_ << " Where is my weapon ?" << std::endl;
}
