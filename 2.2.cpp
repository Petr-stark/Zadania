// 2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
#include <Windows.h>

using namespace std;

/**
* \brief Функция, расчитывающая значение y, если x < 0,5
* \param a - константа, имеющая тип double
* \param x - переменная, имеющая тип double
* \return значение y
**/
double GetY1(const double a, double x);

/**
* \brief Функция, расчитывающая значение y, если x <= 0,5
* \param a - константа, имеющая тип double
* \param x - переменная, имеющая тип double
* \return значение y
**/
double GetY2(const double a, double x);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const double a = 1.36;
	double x;
	cout << "Введите значение x: ";
	cin >> x;
	double y;
	if (x < 0.5) {
		y = GetY1(a, x);
		cout << "Так как x < 0,5 , то y = " << y;
	}
	else {
		y = GetY2(a, x);
		cout << "Так как x => 0,5 , то y =  " << y;
	}
	return 0;
}

double GetY1(const double a, double x) {
	return ( M_PI / 2)+x*a- pow( M_E , (a*x));
}

double GetY2(const double a, double x) {
	return pow(x,3)*a+28;
}