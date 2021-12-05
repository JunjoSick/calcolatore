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

	auto firstGrade() {
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

	auto secondGrade() {
		using a = coefficient[0];
		using b = coefficient[1];
		using c = coefficient[2];

		auto delta = pow(b, 2) - 4 * a * c;
		if (delta < 0) throw NON_SENSE;
		delta = sqrt(delta);
		std::array<double, 2> x = { (-b + delta)/(2 * a), -(b + delta) / (2 * a) };
		return x
	}

	auto thirdGrade() {

	}

public:
	auto solve() {
		switch (coefficient.size()) {
		case 1: firstGrade();
			break;
		case 2: secondGrade();
			break;
		case 3: thirdGrade();
			break;
		default:
			throw std::exception("grado troppo alto");
		}
	}
};
