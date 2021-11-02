﻿// #define _USE_MATH_DEFINES // for C++

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Функция для расчета y
* \param x Параметр a длина участка
* \param x Параметр b ширина участка
* \param x Параметр p длина первого дома
* \param a Параметр q ширина первого дома
* \param x Параметр r длина второго дома
* \param a Параметр s ширина второго дома
*/
bool CanBuid(const double a, const double b, const double p, const double q, const double r, const double s);

/**
* \brief Точка входа в программу
* \return Возвращает нуль, в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	
	double a, b, p, q, r, s;

	cout << "Введите длину участка a = ";
	cin >> a;

	cout << "Введите ширину участка b = ";
	cin >> b;

	cout << "Введите размер длины первого дома p = ";
	cin >> p;

	cout << "Введите размера ширины первого дома q = ";
	cin >> q;

	cout << "Введите размера длины второго дома r = ";
	cin >> r;

	cout << "Введите размера ширины второго дома s = ";
	cin >> s;

	const auto y = CanBuid(a, b, p, q, r, s);

	if (y)

	{
		cout << "Могут быть установленны 2 дома" << endl;
	}

	else

	{
		cout << "Не могут быть установлены 2 дома" << endl;
	}

	return 0;
}

bool CanBuid(const double a, const double b, const double p, const double q, const double r, const double s)
{
	return	((a > p + r) || (a > p + s) || (a > q + r) || (a > q + s)) && ((b > p + r) || (b > p + s) || (b > q + r) || (b > q + s));
}