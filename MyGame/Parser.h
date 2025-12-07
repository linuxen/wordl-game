#pragma once

struct Data {
    char* Path = nullptr;
    int N{};
};

bool Parser(int argc, char* argv[], Data& data);