
//1.2
/**
* \a скорость лодки
* \b скорость течения , если лодка против течени , тогда скорость течение вводим со знаком минус
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
* \param a скорость(мы ее вводим).
* \param t время(мы ее вводим).
* \param b скорость реки(мы ее вводим).
* \return Возвращает путь (S=(a + ( b )) * t ).
*/
int main()
{
	double a ;
	double b ;
	double t ;
	double S ;
	setlocale(LC_ALL, "Russian");
	cout << "Введите скорость\n";
	cin >> a;
	cout << "Введите время\n";
	cin >> t;
	cout << "Введите скорость реки\n";
	cin >> b;
	S = Way (a , t , b );
	cout << "Путь = " << S ;

	return 0;
}
double  Way(double a, double t, double b)
{
	return (a + ( b )) * t ;
}


