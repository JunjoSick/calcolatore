#pragma once

#include <iostream>
#include "calculator.cpp"

inline auto& operator << (std::ostream& out, calculator& a) {
    out << std::showpos;
    for (int i = 0; i <a.coefficients.size(); i++) {
        out <<a.coefficients[i] << "x^" << a.degree()-i  << " ";
    }
    out << std::noshowpos;
    return out;
}