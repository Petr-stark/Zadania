// 1.1
// библиотеки нужные для мат. вычислений
// библиотеки нужные для мат. вычислений
// библиотеки нужные для мат. вычислений
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
#include <Windows.h>
#include "1.1.h"
// нужно чтобы не прописывать std 
using namespace std;

// Объявление функции main()
int main()
{
	const double x = 0.3; //вводим данные
	const double y = 2.9; //вводим данные
	const double z = 0.5; //вводим данные
	const auto a = GetA(x, y, z);
	const auto b = GetB(x, y, z);
	cout << "x = " << x << "\ny = " << y << "\nz = " << z << "\na = " << a << "\nb = " << b;  // вывод данных ,вывод на новою строчку
	return 0;
}
/**
* \GetA Функция для расчета a
* \param x параметр x ,задан в задании
* \param y параметр y ,задан в задании
* \param z параметр z ,задан в задании
* \param e параметр e ,задан в условии
* \return возвращаем значение равное : a
*/
double GetA(const double x, const double y, const double z)

{
	// функция для вычисления переменной а
	return (pow(z, 2) * x + pow(M_E, -x) * cos(y * x)) / (y * x - pow(M_E, -x) * sin(y * x) + 1);
}
/**
* \GetB Функция для расчета b
* \param x параметр x ,задан в задании
* \param y параметр y ,задан в задании
* \param z параметр z ,задан в задании
* \param e параметр e ,задан в условии
* \return возвращаем значение равное : b
*/
double GetB(const double x, const double y, const double z)

{
	// функция для вычисления переменной b
	return pow((M_E), 2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);
}
