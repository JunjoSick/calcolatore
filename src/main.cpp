#pragma once

#include <iostream>

#include <limits>

#include "function.cpp"

#define reset a.coefficients.clear();std::cout << "\n";

int main()
{
	function a;
	double input;
	std::cout.precision(17);
    while(true){
        std::cout << "Type coefficients (type finally a no-double): ";
        while (std::cin >> input) { a.coefficients.emplace_back(input); }

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
                case IMPOSSIBLE: std::cout << "impossible function\n"; reset continue;
                case INDETERMINATE: std::cout << "indeterminate function\n"; reset continue;
                default: std::cout << "Error in first grade function\n"; reset continue;
            }
        }

        for (auto& element : b)
        {
            std::cout << element << "\t";
        }

        reset
    }
	return 0;
}
