#include "Harl.hpp"

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
//staticなのでコンストラクタでは初期化できない

Harl::Harl(void) {
	pointer_[0] = &Harl::debug;
	pointer_[1] = &Harl::info;
	pointer_[2] = &Harl::warning;
	pointer_[3] = &Harl::error;
}

void Harl::complain(std::string level) {
	for(int i = 0; i < 4; ++i)
		if(levels[i] == level) {
			(this->*pointer_[i])();
			return ;
		}
}
//this->*pointer ポインタが指すクラスメンバ（関数またはデータ）を、このオブジェクトに対して参照する
//Harl obj;
//(obj.*pointer)(); オブジェクトの場合

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
