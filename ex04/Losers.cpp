#include "Losers.hpp"
#include <fstream>
#include <stdexcept>

Losers::Losers(const std::string& filename, const std::string& s1, const std::string& s2)
: filename_(filename), s1_(s1), s2_(s2) {}

std::string Losers::replace_line(const std::string& line, const std::string& s1, const std::string& s2) {
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
//std::string::nposはc++98においてstatic const size_type(符号なし整数) = -1(== 最大値)であり、
//「発見できず」や「残り全て」を意味する特異値。

//.find()は文字列から検索対象が出る先頭インデックス(なければnpos)を返す(s1が空だと無限ループのおそれあり)
//.substr()も第2引数を省略するとnpos(=末尾)まで
//.append()はlineのstartからpos-start分をreplaceの末尾に追加

void Losers::replace() {
    std::ifstream ifs(filename_.c_str());
    if (!ifs) throw std::runtime_error("Failed to open infile");

    std::ofstream ofs((filename_ + ".Losers").c_str());
    if (ofs.fail()) throw std::runtime_error("Failed to open outfile");

    std::string line;
    while (std::getline(ifs, line)) {
        ofs << replace_line(line, s1_, s2_);
        if (ifs.peek() != EOF)
            ofs << '\n';
    }
}
//ifstream, ofstreamがコンストラクタでファイルを開こうとする(c++98では.c_strでconst char*にする必要がある)
//(!ifs) == (.fail())
//.peek()で次の文字を消費せずにEOFか確認
