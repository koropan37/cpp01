#ifndef LOSERS_HPP_
#define LOSERS_HPP_

#include <string>

class Losers {
 private:
    std::string filename_;
    std::string s1_;
    std::string s2_;

 public:
    Losers(const std::string& filename, const std::string& s1, const std::string& s2);
    
    void replace();
    static std::string replace_line(const std::string &line, const std::string &s1, const std::string &s2);
};

#endif // REPLACER_HPP
