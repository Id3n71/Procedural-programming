#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

/**
* \brief Функция расчета для случая, когда x > 1.
* \param x Входная величина.
* \param a Входная величина.
* \return Значение функции.
*/
double F1(const double x);
/**
* \brief Функция расчета для случая, когда x <= 1.
* \param x Входная величина.
* \param a Входная величина.
* \return Значение функции.
*/
double F2(const double x, const double a);

/**
* \brief Точка входа в программу.
* \return Код ошибки (0 - успех).
*/
int main()
{
const auto a = 20.3;
const auto comparise = 1;
double x;
cout « "Введите переменную x = ";
cin » x;
double result;
if (x > comparise)
{
result = F1(x);
}
else
{
result = F2(x, a);
}
cout « "y = " « setprecision(15) « result « endl;
return 0;
}

double F1(const double x)
{
return log10(x + 1);
}

double F2(const double x, const double a)
{
return sin(2 * sqrt(abs(a * x)));
}