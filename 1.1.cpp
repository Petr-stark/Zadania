// 1.1
#include <iostream>
#define USE_MATH_DEFINES 
// библиотеки нужные для мат. вычислений
#include <cmath> 
// библиотеки нужные для мат. вычислений
using namespace std; 
// нужно чтобы не прописывать std 
double GetA(const double x, const double y, const double z , const double e)
/**
* \GetA Функция для расчета a
* \param x параметр x ,задан в задании
* \param y параметр y ,задан в задании
* \param z параметр z ,задан в задании
* \param e параметр e ,задан в условии
* \return возвращаем значение равное : a
*/
{ 
	return (pow(z,2) * x + pow ( e,-x) * cos(y * x ))/( y * x - pow(e,-x) * sin(y * x ) + 1 );
	// функция для вычисления переменной а
}

double GetB(const double x, const double y, const double z , const double e ) 
/**
* \GetB Функция для расчета b
* \param x параметр x ,задан в задании
* \param y параметр y ,задан в задании
* \param z параметр z ,задан в задании
* \param e параметр e ,задан в условии
* \return возвращаем значение равное : b
*/
{ 
	return pow(e,2 * x ) * log(z + x) - pow(y , 3 * x ) * log(y - x) ;
	// функция для вычисления переменной b
}
// Объявление функции main()
int main() 
{
	const double x = 0.3; //вводим данные
	const double y = 2.9; //вводим данные
	const double z = 0.5; //вводим данные
	const double e = 2.7; //вводим данные
	const auto a = GetA(x, y, z,e);
	const auto b = GetB(x, y, z ,e);
	cout << "x = " << x << "\ny = " << y << "\nz = " << z << "\ne = " << e << "\na = " << a << "\nb = " << b;  // вывод данных ,вывод на новою строчку
	return 0;
}