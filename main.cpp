#include <iostream>

int main() {
    //TODO: check that guesses are valid words
    //TODO: choose random words from a dictionary
    //TODO: figure out command parsing/flow for tool
    std::string word = "crane";
    int attempts = 0;
    while(attempts < 6){
        std::string guess = "crane";
        if(guess.length() != 5){
            std::cout << "Enter five letters." << std::endl;
        }
        else{
            for(int letter = 0; letter < guess.length(); letter++){
                if(guess[letter] == word[letter]){
                    std::cout  << "\033[1;32m" << guess[letter] << "\033[0m";
                }
                else if((word.find(guess[letter]) != std::string::npos)){
                    std::cout  << "\033[1;33m" << guess[letter] << "\033[0m";
                }
                else{
                    std::cout << guess[letter];
                }
            }
            std::cout << std::endl;
            if(guess == word){
                std::cout << "Congrats!";
                break;
            }
            attempts++;
            if(attempts == 6){
                std::cout << "Better luck next time.";
            }
        }
    }
    return 0;
}
