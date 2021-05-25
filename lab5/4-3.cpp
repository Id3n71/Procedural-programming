#include <random>
#include <iostream>
#include <cmath>

using namespace std;

/*	\brief Функция заполнения массива с клавиатуры
*	\param n количество строк
*	\param m количество стобцов
*	\return Заполненный массив
*/
int** FillKeyboardArray(const size_t n, const size_t m);

/*	\brief Функция заполнения массива случайными числами
*	\param n количество строк
*	\param m количество стобцов
*	\param minValue минимальное значение элемента, заданное пользователем
* 	\param maxValue максимальное значение элемента, заданное пользователем
*	\return Заполненный массив
*/
int** FillRandomArray(const size_t n, const size_t m, const int minValue, const int maxValue);

/*	\brief Функция нахождения максимального по модулю элемента в массиве
*	\param n количество строк
*	\param m количество стобцов
*	\param array введеный массив
*/
int GetMaxElem(int** array, const size_t n, const size_t m);

/*	\brief Функция для определения нового количества строк после преобразований задания 2
*	\param n количество строк
*	\param m количество стобцов
* 	\param array заданный массив
*	\param maxElem максимальный элемент массива
*	\return Новое количество строк
*/
int GetNewAmountOfRows(int** array, const size_t n, const size_t m, const int maxElem);

/*	\brief Функция замены максимального элемента каждого столбца нулевым элементом
*	\param n количество строк
*	\param m количество стобцов
* 	\param array заданный массив
*	\return новый изменённый массив
*/
int** MaxElementToZero(int** array, const size_t n, const size_t m);

/*	\brief Функция вставки после каждого строки, содержащей макисмальный по модулю элемент, первую строку
*	\param n количество строк
*	\param m количество стобцов
* 	\param array заданный массив
* 	\param maxElem максимальный элемент массива
*	\param columns новое количество строк
*	\return новый изменённый массив
*/
int** InsertFirstAfterMax(int** array, const size_t n, const size_t m, const int maxElem);

/*	\brief Вывод массива на консоль
*	\param n количество строк
*	\param m количество столбцов
*	\param array введеный массив
*	\return Массив
*/
void ArrayPrint(int** array, const size_t n, const size_t m);

/* \brief Провека есть ли в столбце максимальный элемент
*	\param n количество строк
* 	\param array заданный массив
*	\param maxElem максимальный элемент массива
*	\param ii индекс номера столбца, используемый в функции InsertFirstAfterMax(...)
* 	\param shift фактор сдвига нового количества столбцов к старому
*	\return True если в стобце есть максимальный элемент
*/
bool GetIsMax(const size_t m, int** array, const int maxElem, const size_t i, int shift);

/* \brief Удаление массива
* \param oldRows количество строк старового массива
* \param n количество строк нового массива
* \param m количество столбцов массива
* \param array массив
*/
void deleteArray(int** array, const size_t n, const size_t m);

/*	\brief Пользовательский выбор, как заполнять массив:
*	случайныи числами (0)
*	или с клавиатуры (1)
*/
enum class InputWay
{
	Random,
	Keyboard
};

/*	\brief Пользовательский выбор, что сделать с массивом:
*	заменить каждый максимальный элемент на нулевой (0)
*	вставить после каждой строки, содержащей максимальный по модулю элемент, первую строку (1)
*/
enum class ActionChoice
{
	MaxToZero,
	FirstAfterMax
};

int main()
{
	cout << " - Rows\n";
	int n;
	cin >> n;

	cout << " - Columns\n";
	int m;
	cin >> m;

	cout << " - Fill the Array:\n (0) for random generation \n (1) for keyboard input \n";
	int input;
	cin >> input;

	int** myArray = 0;

	const auto choiceOne = static_cast<InputWay>(input);
	switch (choiceOne)
	{
	case InputWay::Random:
	{
		cout << " - Input minimum\n";
		int minValue;
		cin >> minValue;

		cout << " - Input maximum\n";
		int maxValue;
		cin >> maxValue;

		myArray = FillRandomArray(n, m, minValue, maxValue);
		for (int i = 0; i < n; i++)
		{
			for (int ii = 0; ii < m; ii++)
				cout << myArray[i][ii] << "\t";
			cout << "\n";
		}
		break;
	}
	case InputWay::Keyboard:
	{
		cout << " - Input numbers you want separating them with 'enter'\n";
		myArray = FillKeyboardArray(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int ii = 0; ii < m; ii++)
				cout << myArray[i][ii] << "\t";
			cout << "\n";
		}
		break;
	}
	}
	if (int maxElem = GetMaxElem(myArray, n, m) == 0)
	{
		cout << "All elements of the array are zero";
		return 1;
	}

	cout << " - Input, which action do you want to initialize: \n "
		<< "   (0) to replace the zero elements with the max element \n "
		<< "   (1) to insert a column with zero elements after column with max element \n";
	cin >> input;

	const auto choiceTwo = static_cast<ActionChoice>(input);
	switch (choiceTwo)
	{
	case ActionChoice::MaxToZero:
	{
		int** newArray = MaxElementToZero(myArray, n, m);

		cout << "New Array:\n";
		ArrayPrint(newArray, n, m);
		deleteArray(newArray, n, m);
		break;
	}
	case ActionChoice::FirstAfterMax:
	{
		int maxElem = GetMaxElem(myArray, n, m);
		int rows = GetNewAmountOfRows(myArray, n, m, maxElem);
		int oldRows = n;
		n = rows;
		int** newArray = InsertFirstAfterMax(myArray, n, m, maxElem);
		deleteArray(myArray, oldRows, m);

		cout << "New Array:\n";
		ArrayPrint(newArray, n, m);
		deleteArray(newArray, n, m);
		break;
	}
	}
	return 0;
}

int** FillKeyboardArray(const size_t n, const size_t m)
{
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[m];
		for (int ii = 0; ii < m; ii++)
		{
			cin >> array[i][ii];
		}
	}
	return array;
}

int** FillRandomArray(const size_t n, const size_t m, const int minValue, const int maxValue)
{
	random_device rd;
	mt19937 gen(rd()); // Генератор случайных чисел

	const uniform_int_distribution<int> uniformIntDistribution(minValue, maxValue); // Границы для случайного числа

	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[m];
		for (int ii = 0; ii < m; ii++)
		{
			array[i][ii] = uniformIntDistribution(gen);
		}
	}
	return array;
}

int GetMaxElem(int** array, const size_t n, const size_t m)
{
	int max = array[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int ii = 0; ii < m; ii++)
		{
			//Поиск максимального элемента в массиве
			if (abs(max) < abs(array[i][ii]) || abs(max) == array[i][ii])
				max = array[i][ii];
		}
	}
	return max;
}

int** MaxElementToZero(int** array, const size_t n, const size_t m)
{
	int maxx = 0; // Переменная для максимального элемента столбца
	const int null = 0;
	for (int ii = 0; ii < m; ii++)
	{
		for (int i = 0; i < n; i++)
		{
			if (array[i][ii] > maxx)
				maxx = array[i][ii]; // Находим максимальный элемент столбца
		}
		for (int i = 0; i < n; i++)
			if (array[i][ii] == maxx)
			{
				array[i][ii] = null; //Максимальный элемент столбца меняем на ноль
				maxx = 0;
			}
	}
	return array;
}

int** InsertFirstAfterMax(int** array, const size_t n, const size_t m, const int maxElem)
{
	int shift = 0; //Переменная как фактор пропуска строки
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			arr[i][j] = array[i - shift][j]; //Новому массиву присвоили старый
		if (GetIsMax(m, array, maxElem, i, shift)) {
			for (int j = 0; j < m; j++) {
				arr[i + 1][j] = array[0][j];
			}
			i++;
			shift++; //Если в строке находится максимальный элемент массива - следующей строкой вставляем первую и пропускаем её.
		}
	}
	return arr;
}

int GetNewAmountOfRows(int** array, const size_t n, const size_t m, const int maxElem)
{
	int row = n;
	for (int i = 0; i < n; i++)
	{
		for (int ii = 0; ii < m; ii++)
		{
			if (array[i][ii] == maxElem)
			{
				row += 1;
				break;
			}
		}
	}
	return row;
}

bool GetIsMax(const size_t m, int** array, const int maxElem, const size_t i, int shift)
{
	for (int index = 0; index < m; index++)
	{
		if (array[i - shift][index] == maxElem)
			return true;
	}
	return false;
}

void ArrayPrint(int** array, const size_t n, const size_t m)
{
	if (array == nullptr)
	{
		cout << "Array doesn't exist";
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int ii = 0; ii < m; ii++)
			{
				cout << array[i][ii] << '\t';
			}
			cout << "\n";
		}
	}
	cout << '\n';
}

void deleteArray(int** array, const size_t n, const size_t m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}