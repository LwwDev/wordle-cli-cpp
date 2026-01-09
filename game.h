#include <iostream>
#include <vector>
#include <string>
#pragma once

class Game{
    public:
        Game();
        void menu();
        void start();
    private:
        std::vector<std::string> words;
        
};