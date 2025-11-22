#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

const std::string &Weapon::getType(void) const { return type_; }

void Weapon::setType(std::string const &type) { type_ = type; }
