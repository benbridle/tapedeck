#include <iostream>
#include <string>
#include <map>
#include "Colour.h"

int main(int argc, char** argv) {

    Colour colour;

    std::cout << colour.getColourEscape(colour.red) << "Test!" << "\n";
    std::cout << colour.getColourEscape(colour.green) << "Test2!" << "\n";
    return 0;
}