#ifndef HARL_CPP_
#define HARL_CPP_

#include <iostream>
#include <string>
class Harl{
 private:
	typedef void (Harl::*MemFuncPtr)(void);
	MemFuncPtr pointer_[4];
	static const std::string levels[4];

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

 public:
	Harl(void);
 	void complain(std::string level);
};

#endif
