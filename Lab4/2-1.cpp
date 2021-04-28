#include <iostream>

using namespace std;

/**
* \brief Пользовательский выбор вывода или месяца (0),
* или дня недели (1)
*/
enum class mainChoice { month, day };

/**
* \brief Пользовательский выбор вывода названия месяца (значения от 1 до 12)
*/
enum class months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

/**
* \brief Пользовательский выбор вывода названия дня недели (значения от 1 до 7)
*/
enum class days { Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun };

/**
* \brief Точка входа в программу.
* \return Код ошибки (0 - успех).
*/
int main()
{

cout « "What do you want to output: month (0) or day of the week (1)" « "\n";
int type;
cin » type;

const auto choice = static_cast<mainChoice>(type);
switch (choice)
{
case mainChoice::month:
{
cout « "Input number of month" « "\n";
int month;
cin » month;

const auto monthChoice = static_cast<months>(month);

switch (monthChoice)
{
case months::Jan:
{
cout « "This is January";
break;
}
case months::Feb:
{
cout « "This is February";
break;
}
case months::Mar:
{
cout « "This is March";
break;
}
case months::Apr:
{
cout « "This is April";
break;
}
case months::May:
{
cout « "This is May";
break;
}
case months::Jun:
{
cout « "This is June";
break;
}
case months::Jul:
{
cout « "This is July";
break;
}
case months::Aug:
{
cout « "This is August";
break;
}
case months::Sep:
{
cout « "This is September";
break;
}
case months::Oct:
{
cout « "This is October";
break;
}
case months::Nov:
{
cout « "This is November";
break;
}
case months::Dec:
{
cout « "This is December";
break;
}
}
break;
}
case mainChoice::day:
{
cout « "Input number of day" « "\n";
int day;
cin » day;

const auto dayChoice = static_cast<days>(day);

switch (dayChoice)
{
case days::Mon:
{
cout « "This is Monday";
break;
}
case days::Tue:
{
cout « "This is Tuesday";
break;
}
case days::Wed:
{
cout « "This is Wednesday";
break;
}
case days::Thu:
{
cout « "This is Thursday";
break;
}
case days::Fri:
{
cout « "This is Friday";
break;
}
case days::Sat:
{
cout « "This is Saturday";
break;
}
case days::Sun:
{
cout « "This is Sunday";
break;
}
}
break;
}
}
cout « endl;
return 0;
}