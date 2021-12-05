#include <math.h>
#include <array>
#include <exception>

enum solution : unsigned char {
	IMPOSSIBLE=0,
	INDETERMINATE
};

template <int size> class equation {
private:

	std::array<double, size> coefficient;

	auto firstGrade() {
		if (coefficient[0] == 0) {
			if (coefficient[1] == 0) {
				throw INDETERMINATE;
			}
			else {
				throw IMPOSSIBLE;
			}
		}
		else {
			return -coefficient[1] / coefficient[a];
		}
	}

	auto secondGrade() {

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
