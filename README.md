# Calculator
A program to solve equations from 1st to 4th (5th and higher wip) grade and determine vampire numbers
## Functions:
```cpp
bool isVampire(natural number);
```
## Classes:
```cpp
function linearEquation;
function quadraticEquation;
function cubicEquation;
function quarticEquation;

linearEquation = {3, 5}; // 3 and 5 are coefficients, 3x+5=0
std::vector<std::complex<double>> solution = linearEquation.zeroes(); //{-5/3,0}

quadraticEquation = {1, 4, 4};
std::vector<std::complex<double>> solutions = quadraticEquation.zeroes(); //{{-2,0}, {-2,0}}

double y = quadraticEquation(2); //1*2^2 + 4*2^1 + 4 = 16
```
