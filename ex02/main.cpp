#include <iostream>
#include <string>

int main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout
		<< "The memory address of the string variable: " << &brain 	   << "\n"
		<< "The memory address held by stringPTR	 : " << stringPTR  << "\n"
		<< "The memory address held by stringREF	 : " << &stringREF << "\n"
		<< "The value of the string variable  : "		 << brain 	   << "\n"
		<< "The value pointed to by stringPTR : "		 << *stringPTR << "\n"
		<< " The value pointed to by stringREF: "		 << stringREF
		<<std::endl;

	return 0;
}
