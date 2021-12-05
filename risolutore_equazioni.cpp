#include <math.h>
#include <array>
template <int size> class equation {
private:

	std::array<double, size> coefficient;

	auto firstGrade() {

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
		}
	}
};
