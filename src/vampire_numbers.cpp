#pragma once

#include <cmath>

#include "number_costraints.cpp"

template <natural t> bool isVampire(t a) {
	if ((trunc(log10(a)) + 1) ^ 1) return false; //if the digits are odd false
	 
}