#include "Losers.hpp"
#include <fstream>
#include <stdexcept>

Losers::Losers(const std::string& filename, const std::string& s1, const std::string& s2)
: filename_(filename), s1_(s1), s2_(s2) {}

std::string Losers::readBuf(std::ifstream& ifs) {
    const std::size_t buf_size = 4096;
    std::string content;
    char buf[buf_size];
    while (ifs.read(buf, buf_size)) {
        content.append(buf, buf_size);
    }
    if (ifs.gcount() > 0) {
        content.append(buf, static_cast<std::size_t>(ifs.gcount()));
    }
    return content;
}
//buf_sizeまで読み、ifs.gcountに格納(読み取り切るまでループ)
//ifs.gcountは読み取ったバイト数を返し、size_tにキャストして渡している

std::string Losers::replaceLine(const std::string& line, const std::string& s1, const std::string& s2) {
    std::string result;
    std::size_t start = 0, pos;
    if (s1.empty()) throw std::runtime_error("s1 is empty");

    while ((pos = line.find(s1, start)) != std::string::npos) {
        result.append(line, start, pos - start);
        result += s2;
        start = pos + s1.length();
    }
    result += line.substr(start);
    return result;
}

void Losers::replace() {
    std::ifstream ifs(filename_.c_str(), std::ios::in | std::ios::binary);
    if (!ifs) throw std::runtime_error("Failed to open infile");

    std::ofstream ofs((filename_ + ".replace").c_str(), std::ios::out | std::ios::binary);
    if (!ofs) throw std::runtime_error("Failed to open outfile");

    std::string content = readBuf(ifs);

    ofs << replaceLine(content, s1_, s2_);
}
