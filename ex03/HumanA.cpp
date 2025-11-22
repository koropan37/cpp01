#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {}

void HumanA::attack(void){
	std::cout << name_ << " attack with " << weapon_.getType() << std::endl;
}
