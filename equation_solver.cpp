#include <math.h>
#include <vector>
#include <exception>
#include <complex>
#include <iostream>
#include <cstdarg>

enum solution:unsigned char
{
  IMPOSSIBLE = 0,
  INDETERMINATE
};
class equation
{
public:

  std::vector < double > coefficient;

private:

    auto firstGrade ()
  {
    auto & a = coefficient[0];
    auto & b = coefficient[1];
    if (a == 0)
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
    else
      {
	std::vector < std::complex < double >> x;
	x.push_back({ -b / a,0}) ;
	return x;
      }
  }
  auto secondGrade ()
  {
    auto & a = coefficient[0];
    auto & b = coefficient[1];
    auto & c = coefficient[2];
    auto delta = pow (b, 2) - 4 * a * c;
    delta = sqrt (abs(delta));
    std::vector < std::complex < double >> x;
	x.push_back({ (-b + delta) / (2 * a),0});
	x.push_back({ -(b + delta) / (2 * a),0}) ;
    return x;
  }
//--------------------- Third grade----------------------
  auto findF (double a, double b, double c)
  {
    return (3.0 * c / a - pow (b, 2) / pow (a, 2)) / 3.0;
  }
  auto findG (double a, double b, double c, double d)
  {
    return (2.0 * pow (b, 3) / pow (a, 3) - 9.0 * b * c / pow (a, 2) +
	    27.0 * d / a) / 27.0;
  }
  auto findH (double g, double f)
  {
    return pow (g, 2) / 4.0 + pow (f, 3) / 27.0;
  }
  auto thirdGrade ()
  {
    auto & a = coefficient[0];
    auto & b = coefficient[1];
    auto & c = coefficient[2];
    auto & d = coefficient[3];
    auto f = findF (a, b, c);
    auto g = findG (a, b, c, d);
    auto h = findH (g, f);
    std::vector < std::complex < double >> x;
    double x1;
    if (f == 0 && g == 0 && h == 0)
      {				// All 3 Roots are Real and Equal
	if ((d / a) >= 0)
	  {
	    x1 = pow ((d / (1.0 * a)), (1 / 3.0)) * -1;
	  }
	else
	  {
	    x1 = pow ((-d / (1.0 * a)), (1 / 3.0));
	  }
	x.push_back({ x1,0 });
	x.push_back({ x1,0 });
	x.push_back({ x1,0 });
	return x;
      }
    else if (h <= 0)
      {				// All 3 roots are Real
	double i = sqrt (pow (g, 2) / 4.0 - h);
	double j = pow (i, 1 / 3.0);
	double k = acos (-(g / (2 * i)));
	double L = j * -1;
	double M = cos (k / 3.0);
	double N = sqrt (3) * sin (k / 3.0);
	double P = (b / (3.0 * a)) * -1;
	x1 = 2 * j * cos (k / 3.0) - (b / (3.0 * a));
	double x2 = L * (M + N) + P;
	double x3 = L * (M - N) + P;
	x.push_back({ x1,0 });;
	x.push_back({ x2,0 });
	x.push_back({ x3,0 });
	return x;
      }
    else if (h > 0)
      {				// One Real Root and two Complex Roots
	double R = -(g / 2.0) + sqrt (h);
	double S, T, U;
	if (R >= 0)
	  S = pow (R, 1 / 3.0);
	else
	  {
	    S = pow (-R, 1 / 3.0) * -1;
	    T = -(g / 2.0) - sqrt (h);
	  }
	if (T >= 0)
	  U = pow (T, 1 / 3.0);
	else
	  U = pow (-T, 1 / 3.0) * -1;
	x1 = (S + U) - (b / (3.0 * a));
	x.push_back({ x1,0 });
	x.push_back({ -(S + U) / 2 - b / (3.0 * a), (S - U) * sqrt(3) * 0.5 });
	x.push_back({ -(S + U) / 2 - b / (3.0 * a),-(S - U) * sqrt(3) * 0.5 });
	return x;
      }
  }

  //------------------Fourth grade---------------------

  auto fourthGrade() {
	  auto& a = coefficient[0];
	  auto& b = coefficient[1];
	  auto& c = coefficient[2];
	  auto& d = coefficient[3];
	  auto& e = coefficient[4];
	  auto q = 12*a*e-3*b*d+c*c;
	  auto s = 27*a*d*d-72*a*c*e+27*b*b*e-9*b*c*d+2*pow(c,3);
	  auto d0 = cbrt((s + sqrt(s * s - 4 * pow(q, 3))) * 0.5);
	  auto p = (8*a*c-3*b*b)/(8*a*a);
	  auto Q = sqrt(-2 / 3 * p+1/(3*a)*(d0+q/d0))*0.5;
	  auto S = (8*a*a*d-4*a*b*c+pow(b,3))/(8*pow(a,3));
	  auto square = 0.5 * sqrt(-4 * Q * Q - 2 * p + S / Q);
	  auto quozient = -b / (4 * a);
	  std::vector < std::complex < double >> x;
	  x.push_back({ quozient - Q + square,0 });
	  x.push_back({ quozient - Q - square,0 });
	  x.push_back({ quozient + Q + square,0 });
	  x.push_back({ quozient + Q - square,0 });
  }

public:

  auto solve ()
  {
    std::vector < std::complex < double >> x;
    switch (coefficient.size())
      {
      case 2:
	x = firstGrade ();
	return x;
      case 3:
	x = secondGrade ();
	return x;
      case 4:
	x = thirdGrade ();
	return x;
      default:
	throw std::runtime_error ("Grade too high");
      }
  }
};

int main ()
{
  equation a;
  a.coefficient = {7, 2};
  auto b = a.solve();
for (auto & element:b)
    {
      std::cout << element << "\t";
    }
  return 0;
}
