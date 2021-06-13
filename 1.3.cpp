//1.3
#include <iostream>
//Подключение библиотеки ввода/вывода  
#include <cmath>
//Подключение математической библиотеки
using namespace std;

double energy (double m, const double c, double t, double t0);
/**
* \Payment-Расчет вес/сила тяжести.
* \param  Q -энергия
* \param  m- масса тела.
* \param  c- удельная теплота плавления.
* \param  t -начальная температура.
* \param  t0 -конечная температура.
* \return Возврат значения.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	double    m , t , t0,Q;
	const double  c = 460.0;
	cout << "Введите массу" << endl;
	cin >> m;
	cout << "Введите начальную температуру" << endl;
	cin >> t;
	cout << "Введите конечную температуру" << endl;
	cin >> t0;
	Q = energy (c,m,t,t0);
	cout << " Энергия = " << Q << endl ;
	return 0;
}
double energy (double m, const double c , double t , double t0)
{
	return c * m *( t0 - t );
}