#ifndef LOSERS_HPP_
#define LOSERS_HPP_

#include <string>

class Losers {
 private:
    std::string filename_, s1_, s2_;

 public:
    Losers(const std::string& filename, const std::string& s1, const std::string& s2);
    void replace();
    std::string readBuf(std::ifstream& ifs);
    std::string replaceLine(const std::string &line, const std::string &s1, const std::string &s2);
};

#endif // REPLACER_HPP
