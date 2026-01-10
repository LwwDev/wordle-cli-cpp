#include <iostream>
#include <vector>
#include <string>
#pragma once

class Game{
    public:
        Game();
        void menu();
        void start();
        std::string picker();
        std::string getValidGuess();
        void evaluateGuess(const std::string& guess, const std::string& secret_word, char colors[5]);
        void updateBoard();
    private:
       std::vector<std::string> words;
        
};