// #define _USE_MATH_DEFINES // for C++

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
bool areaLength(const double a, const double b, const double p, const double q, const double r, const double s);

/**
* \brief Точка входа в программу
* \return Возвращает нуль, в случае успеха
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b, p, q, r, s;

	cout << "Введите значения : учаска , дома-1 , дома-2 a =   b =   p =   q =   r =   s =  " << "\n";
	cin >> a >> b >> p >> q >> r >> s;
	const auto y = areaLength(a, b, p, q, r, s);

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

bool areaLength(const double a, const double b, const double p, const double q, const double r, const double s)
{
	return	((a >= p + r) || (a >= p + s) || (a >= q + r) || (a >= q + s)) && ((b >= p + r) || (b >= p + s) || (b >= q + r) || (b >= q + s));
}