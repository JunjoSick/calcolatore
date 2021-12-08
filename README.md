# Calculator
A program to solve equations from 1 to 3 grade and determine vampire numbers
## Functions:
```cpp
bool isVampire(uint64_t number);
```
## Classes:
```cpp
equation <2> linearEquation;
equation <3> quadraticEquation;
equation <4> cubicEquation;
equation <5> quarticEquation;

linearEquation = {3, 5}; // 3 and 5 are coefficients, 3x+5=0
std::array<std::complex<double>, 1> solution = linearEquation.solve(); //-5/3

quadraticEquation = {1, 4, 4};
std::array<std::complex<double>, 2> solutions = quadraticEquation.solve(); //{-2, -2}
```
