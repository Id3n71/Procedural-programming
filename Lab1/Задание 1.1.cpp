#define _USE_MATH_DEFINES // for C++


#include <iostream>
#include <cmath>

using namespace std;



int main()
{
const auto x = 0.2;
const auto y = 0.004;
const auto z = 1.1;

const auto a = pow(sin(pow(x * x + z, 2), 3))-sqrt(x/y);
const auto b =(x*x)/z+cos(pow(x+y,3))

cout « "x=" « x « ", y=" « y « ", z=" « z « "\n";
cout « "a=" « a « ", b=" « b ;

return 0;
}