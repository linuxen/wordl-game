#include "Parser.h"
#include "Logic.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>


int main(int argc, char* argv[]) {
    Data data;
    Parser(argc, argv, data);

    std::ifstream File(data.Path);
    if(!File.is_open()) {
        throw std::runtime_error("ERROR: The file is not open");
    }

    std::ofstream WordN("WordsOfLengthN.txt");
    if (!WordN.is_open()) {
        throw std::runtime_error("ERROR: WordsOfLengthN.txt is not open");
    }

    char buffer[100];
    int str_count{};
    while (File.getline(buffer, sizeof(buffer))){
        if (strlen(buffer) == data.N) {
            WordN << buffer << '\n';
            str_count++;
        }
    }

    File.close();
    WordN.close(); 

    if (str_count == 0) {
        throw std::runtime_error("ERROR: There are no words of such length");
    }

    srand(time(NULL));
    int rand_number = 1 + rand() % str_count;

    std::ifstream Word("WordsOfLengthN.txt");
    if (!Word.is_open()) {
        throw std::runtime_error("ERROR: Logic");
    }

    char word[100];
    std::string key_word;
    int count{};
    while (Word.getline(word, sizeof(word))){
        count++;
        if (count == rand_number) {
            key_word = word;
        }
    }

    Word.close();

    WordLogic(key_word);
} 