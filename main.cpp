#include <iostream>
#include <fstream>
#include <cctype>
#include "Mindopen.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./mindopen filepath" << std::endl;
        return (1);
    }

    std::ifstream fin(argv[1]);
    Mindopen      interpr;
    char          c;

    try {
        while ((c = fin.get()) != EOF) {
            if (std::isspace(c))
                continue;

            interpr.pushInstruction(c);
        }
    } catch (Mindopen::WrongInstructionException &e) {
        std::cout << e.what() << std::endl;
        fin.close();
        return (1);
    }

    fin.close();

    try {
        interpr.execute();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }

    return (0);
}
