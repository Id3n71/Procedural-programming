#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/*
* \brief Находит третью сторону треугольника
* \param power Значение силы тяги
* \param work Значение совершенной работы
* \return Путь, пройденный автомобилем
*/
double getDistance(double power, double work);

/*
* \brief Переводит в 6 степень
* \param work Значение работы
* \return Работа в мегаджоулях
*/
double getToMega(double work);

/*
* \brief Переводит в 3 степень
* \param power значение силы
* \return Сила в килоньютонах
*/
double getToKilo(double power);

/*
* \brief ¬ход в программу
* \return в случае успеха, возвращает 0
*/

int main()
{
double power, work;
cout « "The value of power: "; cin » power;
cout « "The value of work: "; cin » work;

const double workToMega = getToMega(work);
const double powerToKilo = getToKilo(power);
const double distance = getDistance(powerToKilo, workToMega);

cout « "Distance: " « distance;

return 0;
}

double getDistance(double powerToKilo, double workToMega)
{
return workToMega / powerToKilo; //По формуле из курса физики путь равен делению значения работы на значение силы тяги
}

double getToMega(double work)
{
return work * pow(10, 6); //Перевод работы из мегаджоулей в джоули
}

double getToKilo(double power)
{
return power * pow(10,3); //Перевод силы из килоньютонов в ньютоны
}