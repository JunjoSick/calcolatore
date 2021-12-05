#include <math.h>
#include <array>
#include <exception>

enum solution : unsigned char {
	IMPOSSIBLE=0,
	INDETERMINATE,
	NON_SENSE
};

template <int size> class equation {
private:

	std::array<double, size> coefficient;

	auto& firstGrade() {
		using a = coefficient[0];
		using b = coefficient[1];

		if (a == 0) {
			if (b == 0) {
				throw INDETERMINATE;
			}
			else {
				throw IMPOSSIBLE;
			}
		}
		else {
			std::array<double, 1> x = -b / a;
			return  x
		}
	}

	auto& secondGrade() {
		using a = coefficient[0];
		using b = coefficient[1];
		using c = coefficient[2];

		auto delta = pow(b, 2) - 4 * a * c;
		if (delta < 0) throw NON_SENSE;
		delta = sqrt(delta);
		std::array<double, 2> x = { (-b + delta)/(2 * a), -(b + delta) / (2 * a) };
		return x
	}

	auto findF(double a, double b, double c) {
		return ((3.0 * c / a) - ((b * *2.0) / (a * *2.0))) / 3.0;
	}

	auto findG(double a, double b, double c, double d) {
		return (((2.0 * (b * *3.0)) / (a * *3.0)) - ((9.0 * b * c) / (a * *2.0)) + (27.0 * d / a)) / 27.0;
	}

	auto findH(double g, double f) {
		return ((pow(g, 2) / 4.0 + (pow(f, 3) / 27.0);
	}

	auto& thirdGrade() {
        using a = coefficient[0];
        using b = coefficient[1];
        using c = coefficient[2];
        using d = coefficient[3];
 
		auto f = findF(a, b, c);				
		auto g = findG(a, b, c, d);				
		auto h = findH(g, f);					

		std::array<double, 3> x;
		double x1;

		if (f == 0 && g == 0 && h == 0) { // All 3 Roots are Real and Equal
			if ((d / a) >= 0) {
				x1 = pow((d / (1.0 * a)), (1 / 3.0)) * -1;
			}
			else {
				x1 = pow((-d / (1.0 * a)), (1 / 3.0));
			}
			x = { x1, x1, x1 };
			return x;
		}
		else if (h <= 0) { // All 3 roots are Real
			double i = sqrt(((g * *2.0) / 4.0) - h);
			double j = i * *(1 / 3.0);
			double k = acos(-(g / (2 * i)));
			double L = j * -1;
			double M = cos(k / 3.0);
			double N = sqrt(3) * sin(k / 3.0);
			double P = (b / (3.0 * a)) * -1;

			x1 = 2 * j * cos(k / 3.0) - (b / (3.0 * a));
			double x2 = L * (M + N) + P;
			double x3 = L * (M - N) + P;

			x = { x1, x2, x3 };

			return x;
		}
		/*else if (h > 0) {                                // One Real Root and two Complex Roots
			double R = -(g / 2.0) + sqrt(h);
			double S, T, U;
			if (R >= 0)
				S = R * *(1 / 3.0);
			else {
				S = (-R) * *(1 / 3.0) * -1;
				T = -(g / 2.0) - sqrt(h);
			}
			if (T >= 0)
				U = pow(T, 1 / 3.0);
			else
				U = ((-T) * *(1 / 3.0)) * -1;
			x1 = (S + U) - (b / (3.0 * a));
			double x2 = -(S + U) / 2 - (b / (3.0 * a)) + (S - U) * sqrt(3) * 0.5j; //<- complex number
			double x3 = -(S + U) / 2 - (b / (3.0 * a)) - (S - U) * sqrt(3) * 0.5j; //<- complex number
			x = { x1, x2, x3 };
			return x;
		}*/
	}

public:
	auto& solve() {
		std::array<double, size> x;
		switch (size) {
		case 2: return x = firstGrade();
		case 3: return x = secondGrade();
			break;
		case 4: return x = thirdGrade();
			break;
		default:
			throw std::exception("Grade too high");
		}
	}
};
