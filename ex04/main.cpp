#include <iostream>
#include <fstream>
#include <string>

void replace(const std::string &filename, const std::string &s1, const std::string &s2) {
	std::ifstream ifs(filename.c_str());
	if(!ifs.is_open()) throw std::runtime_error ("Failed to open infile");
	std::ofstream ofs((filename + ".replace").c_str());
	if(!ifs.is_open()) throw std::runtime_error ("Failed to open outfile");
}


int main(int argc, char *argv[]) {
	try {
		if(argc == 4)
			replace(argv[1],argv[2], argv[3]);
		else
			throw std::runtime_error("Usage:<filename> <s1> <s2>");
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
