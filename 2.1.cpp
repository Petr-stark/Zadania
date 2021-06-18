// 2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//подключение библиотеки ввода/вывода

//подключение библиотеки ввода/вывода
#include  <iostream>
//подключение математической библиотеки 
#include <cmath>
#include <string>
using namespace std;
/**
* \Sum Функция для расчета суммы  
* \param a число
* \param b число
* \param c число
* \return возврощает значение суммы
*/
double Sum( double a,  double b,  double c);
/**
* \ Number_of_negative_numbers Функция для расчета  отрицательных чисел
* \param a число
* \param b число
* \param c число
* \return возврощает значение   расчета  отрицательных чисел
*/
double Number_of_negative_numbers(double a, double b, double c);
/**
* \brief Перечислимый тип чисел, с помощью которого можно посчитать 
*/
enum class Choice
{
	/**
	* \brief Выбор пользователя - суммы
	*/
	 Sum= 1,

	/**
	* \brief Выбор пользователя - колличество отрицательных чисел
	*/
	Number_of_negative_numbers = 2
};
/**
* \brief
* \param message
* \return
*/
Choice ReadUserChoice(const string& Message = "");

/**
* \brief Точка входа в программу.
* \return Код ошибки, если 0 - успешное выполнение.
*/

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	const auto message = "Выберите, что нужно посчитать:\n"
		+ to_string(static_cast<int>(Choice::Sum)) + " - Сумма\n"
		+ to_string(static_cast<int>(Choice::Number_of_negative_numbers)) + " - Колличество отриательных чисел \n";
	const auto Number = ReadUserChoice(message);
	switch (Number)
	{
	case Choice::Sum:
	{
		cout << "Введите три числа" << endl;
		cin >> a >> b >> c;
		
		cout << "Сумма = " << Sum(a, b, c) << endl;
		break;
	}
	case Choice::Number_of_negative_numbers:
	{
		cout << "Введите три числа" << endl;
		cin >> a >> b>>c;
		cout << "Колличество отриательных чисел = " <<Number_of_negative_numbers(a, b,c) << endl;
		break;
	}
	default:
		cout << "Ошибка!";
	}
	system("pause");

	return 0;
}
Choice ReadUserChoice(const string& message)
{
	cout << message;
	int UserInput;
	cin >> UserInput;
	return static_cast<Choice>(UserInput);
}
double Sum( double a,  double  b, double  c)
{

	return abs(a) + abs(b) + abs(c);
}
double Number_of_negative_numbers( double a,  double  b , double c)
{
	double i;
	if (a < 0 && b < 0 && c < 0) {
		i = 1;
	}
	if (a < 0 && b < 0 || a < 0 && c < 0 || b < 0 && c < 0) {
		i = 2;
	}
	if (a < 0 && b < 0 && c < 0) {
		i = 3;
	}
	return i;
}


