#include <iostream>
#include <vector>
#include <string>
#pragma once

class Game{
    public:
        Game();
        void menu();
        void start();
<<<<<<< HEAD
        std::string picker();
        std::string getValidGuess();
        void evaluateGuess(const std::string& guess, const std::string& secret_word, char colors[5]);
        void updateBoard();
    private:
       std::vector<std::string> words;
=======
    private:
        std::vector<std::string> words;
>>>>>>> af305c9083871968755d3fa7d13a7d92e20064c4
        
};