#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <iostream>
#include <string>

class Weapon {
 private:
	std::string type_;
 public:
	Weapon(std::string type);

	std::string const &getType()const;
	void setType(std::string const &type);
};


#endif
