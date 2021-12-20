#pragma once

#include <iostream>

#include <limits>

//TODO: This should be changed to include header files and not the cpp ones.
#include "calculator.cpp"
#include "utils.cpp"

#define reset a.coefficients.clear();std::cout << "\n";

int main()
{
	calculator a;
	double input;
	std::cout.precision(17);
    while(true){
        std::cout << "Type coefficients: ";
        while((std::cin.peek() != '\n') && std::cin >> input) { a.coefficients.emplace_back(input); }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (a.coefficients.empty()) { return 0; } //exit from loop

        for (int i = 0; a.coefficients[i] == 0 && i < a.degree()-1; i++) {
            a.coefficients.erase(a.coefficients.begin());
        }

        std::cout << "Input: " << a <<"\n";

        decltype(a.zeroes()) b;

        try {
            b = a.zeroes();
        }
        catch (solution& s) {
            switch (s) {
                case IMPOSSIBLE: std::cout << "impossible calculator\n"; reset continue;
                case INDETERMINATE: std::cout << "indeterminate calculator\n"; reset continue;
                default: std::cout << "Error in first grade calculator\n"; reset continue;
            }
        }

        for (auto& element : b)
        {
            std::cout << element << "\t";
        }

        reset
    }
}
