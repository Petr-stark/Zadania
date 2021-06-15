// 2.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

/**
* \brief Метод, определяющий время суток
* \param a - длина участка
* \param b - ширина участка
* \param p - длина дома-1
* \param q - ширина дома-1
* \param r - длина дома-2
* \param s - ширина дома-2
**/
void constructionsite(int a, int b , int p, int q, int r, int s);

/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	cout << "enter the length of the plot a: ";
	int a;
	cin >> a;
	cout << "enter the width of the plot b: ";
	int b;
	cin >> b;
	cout << "enter the length of the house-1 p: ";
	int p;
	cin >> p;
	cout << "enter the width of the house-1 q: ";
	int q;
	cin >> q;
	cout << "enter the length of the house-2 r: ";
	int r;
	cin >> r;
	cout << "enter the width of the house-2 s: ";
	int s;
	cin >> s;
	constructionsite(a,b,p,q,r,s);
	return 0;
}

void constructionsite(int a, int b , int p , int q ,int r, int s)
{
	const int length = a;
	const int width = b;

	if ( p >= length && q >= width)
		cout << "The house-1 cannot be installed!";
	
	if (r >= length && s >= width)
		cout << "The house-2 cannot be installed!";

	if (p <= length && q <= width)
		cout << "The house-1 can be installed!";
	
	if (r <= length && s <= width)
		cout << "The house-2 can be installed!";

	if ((p+r) > length && (q+s) > width)
		cout << "The house-1,2 cannot be installed!";

	if ((p) <= length && (r) <= length && (q + s) <= width)
		cout << "The house-1,2 can be installed!";
}