//1.2 задание Вычислить путь, пройденный лодкой по течению, если известна ее скорость в стоячей воде, скорость течения реки и время движения
/**
* \v скорость судна
* \v2 скорость течения , если лодка против течени , тогда скорость течение вводим со знаком минус
* \t время пути
* \s путь лодки
*/
#include <iostream>
//подключение библиотеки ввода/вывода
#include <cmath>
//подключение математической библиотеки 
using namespace std;
double space(double a ,double time ,double v2);
/**
* \Путь- Функции пути.
* \param v скорость судна(мы ее вводим).
* \param time время(мы ее вводим).
* \param v2 скорость реки(мы ее вводим).
* \return Возвращает путь (s=(v + ( v2 )) * t ).
*/
int main()
{
	double v ; 
	double v2 ;
	double time ;
	double s ;
	setlocale(LC_ALL, "Russian");
	cout << "Введите скорость судна\n";
	cin >> v;
	cout << "Введите время\n";
	cin >> time;
	cout << "Введите скорость реки\n";
	cin >> v2;
	s = space(v , time , v2 );
	cout << "Путь = " << s ;

	return 0;
}
double  space(const double v, const double time, const double v2)
{
	return (v +  v2 ) * time ;
}


