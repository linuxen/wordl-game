#include <iostream>
#include <cstring>

int WordLogic(std::string key_word){
    if (key_word == "") {
        throw std::runtime_error("ERROR: No key word");
    }

    std::cout << "У тебя есть 5 попыток угадать слово" << '\n';

    for (int i = 1; i <= 5; i++) {
        std::string possible_word;
        std::cout << "Попытка номер: " << i << '\n';
        std::cin >> possible_word;
        if (possible_word == key_word) {
            std::cout << "WINNER!!!" << '\n';
            break;
        }

        else  {
            for (int i = 0; i < key_word.length(); i++) {
                if (possible_word[i] == key_word[i]) std::cout << '+';
                else if (key_word.find(possible_word[i]) != std::string::npos) std::cout << '=';
                else std::cout << '-';
            }
            std::cout << '\n';
        }
    }

    std::cout << "The word was: " << key_word << '\n';

    return 0;
}