#pragma once

#include <cstdlib>
#include <iostream>
#include <array>
#include <string>

struct Painter {
    Painter(){
        colorStrings = {{
            std::string("\033[1m\033[0m"),
            std::string("\033[1m\033[30m"), std::string("\033[1m\033[31m"),
            std::string("\033[1m\033[32m"), std::string("\033[1m\033[33m"),
            std::string("\033[1m\033[34m"), std::string("\033[1m\033[35m"),
            std::string("\033[1m\033[36m"), std::string("\033[1m\033[37m")
        }};
    }

    static Painter* GetInstance() {
        if (Painter::instance != nullptr) return Painter::instance;
        Painter::instance = new Painter();
        return Painter::instance;
    }

    std::string GetColor(int num) {
        if (num < 0) return "";
        return colorStrings[num % 9];
    }

private:
    std::array<std::string, 9> colorStrings;
    static Painter* instance;
};


