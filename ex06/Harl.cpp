#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(void) {
	pointer_[0] = &Harl::debug;
	pointer_[1] = &Harl::info;
	pointer_[2] = &Harl::warning;
	pointer_[3] = &Harl::error;
}

void Harl::complain(std::string level) {
	int i;

	for(i = 0; i < 4; ++i)
		if(levels[i] == level) break;
	switch (i)
	{
	case 0:
		(this->*pointer_[i++])(); //debug()
		/* fall through */
	case 1:
		(this->*pointer_[i++])();//info()
		/* fall through */
	case 2:
		(this->*pointer_[i++])();//warning()
		/* fall through */
	case 3:
		(this->*pointer_[i])();//error()
		break;
	default:
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
// /* fall through */でbreakまで処理(なくても動いた)

void Harl::debug(void) {
	std::cout
		<< "[DEBUG]   "
		<< "I love having extra bacon for my "
		<<"7XL-double-cheese-triple-pickle-specialketchup burger."
		<< "I really do!"
		<<std::endl;
}

void Harl::info(void) {
	std::cout
		<< "[INFO]    "
		<<  "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did,"
		<< "I wouldn’t be asking for more!"
		<<std::endl;
}

void Harl::warning(void) {
	std::cout
		<< "[WARNING] "
		<< "I think I deserve to have some extra bacon for free."
		<< "I’ve been coming for years,"
		<< "whereas you started working here just last month."
		<<std::endl;
}

void Harl::error(void) {
	std::cout
		<< "[ERROR]   "
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}
