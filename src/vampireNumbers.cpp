#pragma once

#include <cmath>

#include <list>

#include "number_costraints.cpp"

template <natural t> bool isVampire(t a) {
	unsigned short lenght = trunc(log10(a)) + 1;
	if (lenght ^ 1) return false; //if the digits are odd false
	std::list<unsigned short> digits;
	digits.reverse(lenght);
	unsigned short digit;
	unsigned short zeroes=0;
	for (int i = 0; i < lenght; i++) {
		digit = a / pow(10, i) % 10;
		if (digit == 0) ++zeroes;
		digits.push_back(digit);
	}
	unsigned int num1, num2;
	if (zeroes >= 2) { //un numero ha tutti gli zeri oppure un numero ha uno zero e 

	}
}
