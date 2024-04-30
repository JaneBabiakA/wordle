#include <iostream>
#include <fstream>
#include <string>

int main() {
    //TODO: check that guesses are valid words
    //TODO: figure out command parsing/flow for tool
    srand(time(0));
    int line = rand() % 2316;
    std::ifstream file ("/home/janef/CLionProjects/wordle/words.txt");
    file.seekg(line * 6);
    std::string word;
    std::getline(file, word);
    int attempts = 0;
    while(attempts < 6){
        std::string guess;
        std::cin >> guess;
        std::cout << "\033[A";
        if(guess.length() != 5){
            if(guess == "exit"){
                return 0;
            }
            else if(guess == "help"){
                std::cout << "Enter your guesses. Type 'exit' to quit.";
            }
            else{
                std::cout << "Enter five letters or a command (exit, help)." << std::endl;

            }
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
                std::cout << "Congrats!" << std::endl;
                break;
            }
            attempts++;
            if(attempts == 6){
                std::cout  << "\033[1;32m" << word << "\033[0m" << std::endl;
                std::cout << "Better luck next time!" << std::endl;
            }
        }
    }
    return 0;
}
