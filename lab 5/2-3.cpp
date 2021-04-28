#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void TriangleSquare();
void QuadrateSquare();
void RhombusSquare();
void RectangleSquare();

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int figure;
	cout << "Выберите фигуру и введите ее порядковый номер:\n" << "Треугольник - 1\n" << "Квадрат - 2\n" << "Ромб - 3\n" << "Прямоугольник - 4\n";
	cin >> figure;
	switch (figure) {
	case 1:
		TriangleSquare();
		break;
	case 2:
		QuadrateSquare();
		break;
	case 3:
		RhombusSquare();
		break;
	case 4:
		RectangleSquare();
		break;
	}
}

void TriangleSquare() {
	cout << "S = 1/2 * a * h, где a - основание треугольника, h - высота, проведенная к основанию a";
}

void QuadrateSquare() {
	cout << "S = a * a, где a - сторона квадрата";
}

void RhombusSquare() {
	cout << "S = 1/2 * d1 * d2, где d1, d2 - диагонали ромба";
}

void RectangleSquare() {
	cout << "S = a * b, где a, b - смежные стороны прямоугольника";
}