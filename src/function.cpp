#pragma once

#include <cmath>
#include <complex>

#include <random>

#include <vector>
#include <initializer_list>

#include <iostream>

#include "number_costraints.cpp"

enum solution :unsigned char
{
	IMPOSSIBLE = 0,
	INDETERMINATE
};

const double pi = 2.0 * acos(0.0);
const double zeroApproximation = 1.e-15;

class function
{
public:

	std::vector < double > coefficients;

	function() = default;

	function(std::initializer_list<double> list) : coefficients(list) {}
	//TODO to write number instead of typename
	template <typename t> double operator ()(t a) {
		double b = 0;
		for (int i = 0; i < coefficients.size(); i++) {
			b += coefficients[i] * pow(a, i);
		}
		return b;
	}

	inline auto degree() {
		return coefficients.size() - 1;
	}

	auto derivative(double x) {
		return ((*this)(x + 1.e-15) - (*this)(x)) / 1.e-15;
	}

private:

	auto firstGrade()
	{
		auto& a = coefficients[0];
		auto& b = coefficients[1];

		if (a != 0)
		{
			std::vector < std::complex < double >> x;
			x.emplace_back(-b / a, 0);
			return x;
		}
		else
		{
			if (b == 0)
			{
				throw INDETERMINATE;
			}
			else
			{
				throw IMPOSSIBLE;
			}
		}
	}
	auto secondGrade()
	{
		auto& a = coefficients[0];
		auto& b = coefficients[1];
		auto& c = coefficients[2];

		std::complex<double> delta = { pow(b, 2) - 4 * a * c, 0 };
		delta = sqrt(delta);

		std::vector < std::complex < double >> x;
		x.reserve(2);
		x.emplace_back((-b + delta) / (2 * a));
		x.emplace_back(-(b + delta) / (2 * a));

		return x;
	}
	//--------------------- Third grade----------------------
	inline auto findF(double a, double b, double c)
	{
		return (3.0 * c / a - pow(b, 2) / pow(a, 2)) / 3.0;
	}
	inline auto findG(double a, double b, double c, double d)
	{
		return (2.0 * pow(b, 3) / pow(a, 3) - 9.0 * b * c / pow(a, 2) +
			27.0 * d / a) / 27.0;
	}
	inline auto findH(double g, double f)
	{
		return pow(g, 2) / 4.0 + pow(f, 3) / 27.0;
	}
	auto thirdGrade()
	{
		auto& a = coefficients[0];
		auto& b = coefficients[1];
		auto& c = coefficients[2];
		auto& d = coefficients[3];

		auto f = findF(a, b, c);
		auto g = findG(a, b, c, d);
		auto h = findH(g, f);

		std::vector < std::complex < double >> x;
		double x1;
		if (f == 0 && g == 0 && h == 0)
		{				// All 3 Roots are Real and Equal
			if ((d / a) >= 0)
			{
				x1 = pow((d / (1.0 * a)), (1 / 3.0)) * -1;
			}
			else
			{
				x1 = pow((-d / (1.0 * a)), (1 / 3.0));
			}
			x.reserve(3);
			x.emplace_back(x1, 0);
			x.emplace_back(x1, 0);
			x.emplace_back(x1, 0);
			return x;
		}
		else if (h <= 0)
		{				// All 3 roots are Real
			double i = sqrt(pow(g, 2) / 4.0 - h);
			double j = pow(i, 1 / 3.0);
			double k = acos(-(g / (2 * i)));
			double L = j * -1;
			double M = cos(k / 3.0);
			double N = sqrt(3) * sin(k / 3.0);
			double P = (b / (3.0 * a)) * -1;
			x1 = 2 * j * cos(k / 3.0) - (b / (3.0 * a));
			double x2 = L * (M + N) + P;
			double x3 = L * (M - N) + P;
			x.reserve(3);
			x.emplace_back(x1, 0);
			x.emplace_back(x2, 0);
			x.emplace_back(x3, 0);
			return x;
		}
		else // h > 0
		{				// One Real Root and two Complex Roots
			auto R = -(g / 2.0) + sqrt(h);
			decltype(R) S;
			if (R >= 0) S = pow(R, 1 / 3.0);
			else S = pow(-R, 1 / 3.0) * -1;
			auto T = -(g / 2.0) - sqrt(h);
			decltype(T) U;
			if (T >= 0)	U = pow(T, 1 / 3.0);
			else U = pow(-T, 1 / 3.0) * -1;
			x1 = (S + U) - (b / (3.0 * a));
			x.reserve(3);
			x.emplace_back(x1, 0);
			x.emplace_back(-(S + U) / 2 - b / (3.0 * a), (S - U) * sqrt(3) * 0.5);
			x.emplace_back(-(S + U) / 2 - b / (3.0 * a), -(S - U) * sqrt(3) * 0.5);
			return x;
		}
	}

	//------------------Fourth grade---------------------

	auto fourthGrade() {
		auto& a = coefficients[0];
		auto& b = coefficients[1];
		auto& c = coefficients[2];
		auto& d = coefficients[3];
		auto& e = coefficients[4];

		auto q = 12 * a * e - 3 * b * d + c * c;
		auto s = 27 * a * d * d - 72 * a * c * e + 27 * b * b * e - 9 * b * c * d + 2 * pow(c, 3);
		auto d0 = pow((s + sqrt(static_cast<std::complex<double>>(s * s - 4 * pow(q, 3)))) * 0.5, 1 / 3);
		auto p = (8 * a * c - 3 * b * b) / (8 * a * a);

		auto Q = sqrt(-2 / 3 * p + 1 / (3 * a) * (d0 + q / d0)) * 0.5;
		auto S = (8 * a * a * d - 4 * a * b * c + pow(b, 3)) / (8 * pow(a, 3));
		auto square = 0.5 * sqrt(-4.0 * Q * Q - 2 * p + S / Q);
		auto quozient = -b / (4 * a);

		std::vector < std::complex < double >> x;
		x.reserve(4);
		x.emplace_back(quozient - Q + square);
		x.emplace_back(quozient - Q - square);
		x.emplace_back(quozient + Q + square);
		x.emplace_back(quozient + Q - square);
		return x;
	}

	//------------------fifth grade and higher------------------------

	inline void getUpperLowerBounds(double& upper, double& lower) {
		auto degree = this->degree();
		auto max = *std::max_element(coefficients.begin(), coefficients.end(), [](double& a, double& b)
			{
				return abs(a) < abs(b);
			});
		upper = 1 + 1 / abs(coefficients[degree]) * max;
		lower = abs(coefficients[0]) / (abs(coefficients[0]) + max);
	}

	inline auto initializeRoots() {
			auto degree = this->degree();
			double upper, lower;
			getUpperLowerBounds(upper, lower);

			std::vector<std::complex<double>> roots;
			roots.reserve(degree);

			double radius, angle;

			std::random_device rand;
			std::uniform_real_distribution distribution;
			for (int i = 0; i < degree; i++) {
				distribution = std::uniform_real_distribution(lower, upper);
				radius = distribution(rand);
				distribution = std::uniform_real_distribution(0.0, pi*2);
				angle = distribution(rand);
				roots[i] = { radius * cos(angle), radius * sin(angle) };
			}
			return roots;
	}
	auto genericGrade() {
		auto x = initializeRoots();
		while (true){
			unsigned int valid = 0;
			double ratio;
			std::complex<double> sum, offset;
			for (int k = 0; k < x.size(); k++) {
				ratio = (*this)(k) / this->derivative(k);
				for (int j = 0; j < k; j++) {
					sum += 1.0 / (x[k] - x[j]);
				}
				offset = ratio / (std::complex<double>(1,0) - ratio * sum);
					if (offset.real() == 0 && offset.imag() == 0) valid += 1;
				x[k] -= offset;
			}
			if (valid == coefficients.size()) break;
		}
		return x;
	}

public:

	auto zeroes() //assume grade is higher than 0
	{
		std::vector < std::complex < double >> x;
		switch (coefficients.size())
		{
		case 2:
			try {
				x = firstGrade();
			}
			catch (solution& s) { throw s; }
			break;
		case 3:
			x = secondGrade();
			break;
		case 4:
			x = thirdGrade();
			break;
		case 5:
			x = fourthGrade();
			break;
		default:
			x = genericGrade();
			break;
		}
		for (auto& i : x) {
			if (i.real() <= zeroApproximation) i.real(0);
			if (i.imag() <= zeroApproximation) i.imag(0);
		}
		return x;
	}
};

auto& operator << (std::ostream& out, function& a) {
	out << std::showpos;
	for (int i = 0; i <a.coefficients.size(); i++) {
		out <<a.coefficients[i] << "x^" << a.degree()-i  << " ";
	}
	out << std::noshowpos;
	return out;
}