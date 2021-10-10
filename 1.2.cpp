﻿
//1.2
/**
* \v скорость лодки
* \a скорость течения , если лодка против течени , тогда скорость течение вводим со знаком минус
* \t время пути
* \S путь лодки
*/
#include <iostream>
//подключение библиотеки ввода/вывода
#include <cmath>
//подключение математической библиотеки 
using namespace std;
double Way(double a ,double t ,double b);
/**
* \Путь- Функции пути.
* \param v скорость(мы ее вводим).
* \param t время(мы ее вводим).
* \param a скорость реки(мы ее вводим).
* \return Возвращает путь (S=(v + ( a )) * t ).
*/
int main()
{
	double v ;
	double a ;
	double t ;
	double S ;
	setlocale(LC_ALL, "Russian");
	cout << "Введите скорость судна\n";
	cin >> v;
	cout << "Введите время\n";
	cin >> t;
	cout << "Введите скорость реки\n";
	cin >> a;
	S = Way (v , t , a );
	cout << "Путь = " << S ;

	return 0;
}
double  Way(const double v, const double t, const double a)
{
	return (v +  a ) * t ;
}


