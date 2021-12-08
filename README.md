# Calculator
A program to solve equations from 1 to 3 grade and determine vampire numbers
## Functions:
```cpp
bool isVampire(uint64_t number);
```
## Classes:
```cpp
equation linearEquation;
equation quadraticEquation;
equation cubicEquation;
equation quarticEquation;

linearEquation = {3, 5}; // 3 and 5 are coefficients, 3x+5=0
std::vector<std::complex<double>> solution = linearEquation.solve(); //{-5/3,0}

quadraticEquation = {1, 4, 4};
std::vector<std::complex<double>> solutions = quadraticEquation.solve(); //{{-2,0}, {-2,0}}
```
