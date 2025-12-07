#include "Parser.h"

#include <iostream>

bool Parser(int argc, char** argv, Data& data) {
    if (argc > 3) {
        throw std::runtime_error("ERROR: Lots of files");
    }

    data.Path = argv[1];

    int value = std::stoi(argv[2]);
    data.N = value;

    if (!data.Path && !data.N) {
        throw std::runtime_error("ERROR: No file");
    } 

    return 0;
}