#include <iostream>
#include <cstdlib>
#include "Losers.hpp"

int main(int argc, char *argv[]) {
    try {
        if (argc == 4) {
            Losers sed(argv[1], argv[2], argv[3]);
            sed.replace();
        } else {
            throw std::runtime_error("Usage:<filename> <s1> <s2>");
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
