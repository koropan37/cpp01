#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string replace_line(const std::string &line, const std::string &s1, const std::string &s2) {
	std::string replace;
	std::size_t start = 0, pos;

	while((pos = line.find(s1, start)) != std::string::npos){
		replace.append(line,start, pos - start);
		replace += s2;
		start = pos + s1.length();
	}
	replace += line.substr(start);
	return replace;
}
//std::string::nposはc++98においてstatic const size_type(符号なし整数) = -1(== 最大値)であり、
//「発見できず」や「残り全て」を意味する特異値。
//std::string.substrも第2引数を省略するとnpos(=末尾)まで

void replace(const std::string &filename, const std::string &s1, const std::string &s2) {
	if(s1.empty()) throw std::runtime_error ("s1 is empty");

	std::ifstream ifs(filename.c_str());
	if(!ifs) 		throw std::runtime_error ("Failed to open infile");

	std::ofstream ofs((filename + ".replace").c_str());
	if(ofs.fail()) 	throw std::runtime_error ("Failed to open outfile");

	std::string line;
	while(std::getline(ifs, line)) {
		ofs << replace_line(line, s1, s2);
		if(!ifs.eof())
			std::cout << std::endl;
	}
}
//ifstream, ofstreamがコンストラクタでファイルを開こうとする(c++98では.c_strでconst char*にする必要がある)
//

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
