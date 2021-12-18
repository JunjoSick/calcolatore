#include <iostream>

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

        decltype(a.zeroes()) b;

        try {
            b = a.zeroes();
        }
        catch (solution& s) {
            switch (s) {
                case IMPOSSIBLE: std::cout << "impossible function"; continue;
                case INDETERMINATE: std::cout << "indeterminate function"; continue;
                default: std::cout << "Error in first grade function"; continue;
            }
        }

        for (auto& element : b)
        {
            std::cout << element << "\t";
        }

        a.coefficients.clear();

        std::cout << "\n";
    }
	return 0;
}
