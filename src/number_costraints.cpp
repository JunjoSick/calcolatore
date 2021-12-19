#pragma once

#include <concepts>

template <typename t> concept natural = std::unsigned_integral<t>;
//template <typename t> concept number = std::integral<t> || std::floating_point<t> || std::is_same<t, std::complex<double>>::value;