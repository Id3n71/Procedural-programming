#include <iomanip>
#include <iostream>

using namespace std;

/*
* \brief Подсчет рекуррентной функции
* \param x значение x
* \param index значение n в форумуле
* \return рекуррентное значение
*/
double Recurrent(const unsigned int index, const double x);

/*
* \brief Подсчет суммы ряда
* \param x значение x с шагом 0,01
* \param epsilon точность
* \return значение суммы
*/
double GetSumRow(const double x, const double epsilon);

/*
* \brief Подсчет функции с экспонентой.
* \param x степень.
* \return Значение функции в x.
*/
double GetExpPowerX(const double x);

/**
* \brief Точка входа в программу.
* \return Код ошибки (0 - верно).
*/
int main()
{
const auto leftBorder = 0.1;
const auto rightBorder = 1.0;
const auto epsilon = 0.0001;
const auto step = 0.01;

auto x = leftBorder;
while (x <= rightBorder + epsilon)
{
const auto func = GetExpPowerX(x);
const auto row = GetSumRow(x, epsilon);
cout « setw(10) « x « " | " « setw(15) « func « " | " « x15) « row « "\n";
x += step;
}

return 0;
}

double GetExpPowerX(const double x)
{
return (exp(x) + exp(-x)) / 2;
}

double Recurrent(const unsigned int index, const double x)
{
return pow(x, 2) / (2 * index);
}

double GetSumRow(const double x, const double epsilon)
{
auto previous = 0.0;
auto current = 1.0;
auto sum = current;
unsigned int index = 1;
do
{
previous = current;
current = previous * Recurrent(index, x);
sum += current;
index++;
} while (abs(previous - current) <= epsilon);

return sum;
}