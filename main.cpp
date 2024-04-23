#include <iostream>

int main() {
    std::string word = "crane";
    std::string guess;
    std::cin >> guess;
    for(char letter = 0; letter <= guess.length(); letter++){
        if(guess[letter] == word[letter]){
            std::cout << guess[letter];
            std::cout << "^[35mTexting^[0m";

        }
        else{
            std::cout << "*";
        }
    }
    return 0;
}
