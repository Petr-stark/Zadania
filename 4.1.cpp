// 4.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;


/**
* \brief Заполнение массива случайными числами
* \param array Массив
* \param size Размер массива
* \param LOW_BOUND Минимально возможное число
* \param UP_BOUND Максимально возможное число
**/
void randomDigits(int* array, const size_t  size, const int LOW_BOUND, const int UP_BOUND);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void userInput(int* array, const int  size);

/**
* \brief Вывод массива
* \param array Массив
* \param size Размер массива
**/
void Print(int* array, const int size);

/**
* \brief Сумма элементов , значения которых состоят из 1 числа
* \param array Массив
* \param size Размер массива
* \param return Значение суммы
**/
int GetSum(int* array, const int size);

/**
* \brief Замена массива
* \param array Массив
* \param size Размер массива
**/
void numberGreaterNext(int* array, const int size);

/**
* \brief Номера пар соседних элементов массима , произведения которых меньше числа k
* \param array Массив
* \param size Размер массива
**/
void multiplyАllmultiplesThrebyThirdElement(int* array, const int size , const int k);

/**
* \brief Выбор заполнеия массива
**/
enum class Filling
{
	RANDOM = 1,
	USER = 2
};


/**
* \brief Точка входа в программу
* \return Код ошибки (0-успех)
**/
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int LOW_BOUND = -100, UP_BOUND = 100;

	cout << "Введите количество элементов массива: ";
	int* array;
	int size;
	
	cin >> size;
	cout << "Введите число (ограничение) для 3-его задания ";
	int k;
	cin >> k ;

	array = new int[size];
	cout << "1 - Сгенерировать массив\n2 - Заполнить массив вручную\n";
	int choice;
	cin >> choice;

	const auto filling = static_cast<Filling>(choice);
	switch (filling)
	{
	case Filling::RANDOM:
		randomDigits(array, size, LOW_BOUND, UP_BOUND);
		Print(array, size);
		break;
	case Filling::USER:
		userInput(array, size);
		Print(array, size);
		break;
	default:
		cout << "Ошибка! Не выбран ни один из вариантов";
	}

	cout << "Сумма элементов,  которые состоят из 1 цыфры = " << GetSum(array, size) << "\n\n";

	cout << "Замена элементов массива между мин. и максм. на те же элементы в обратном порядке :\n";
	numberGreaterNext(array, size);

	cout << "Номер  пары соседних элементов с одинаковыми знаками :\n";
	multiplyАllmultiplesThrebyThirdElement (array, size,k );

	delete[] array;

	return 0;
}

void randomDigits(int* array, const size_t  size, const int LOW_BOUND, const int UP_BOUND) {
	for (size_t i = 0; i < size; i++) {
		array[i] = rand() % (2 * UP_BOUND + 1) + LOW_BOUND;
	}
}

void userInput(int* array, const int  size) {
	for (size_t i = 0; i < size; i++) {
		cout << "arr[" << i << "] = ";
		cin >> array[i];
	}
}

void Print(int* array, const int size) {
	cout << "array[" << size << "]" << "= {";
	for (size_t i = 0; i < size - 1; i++) {
		cout << array[i] << ";" << setw(3);
	}
	cout << array[size - 1] << "}\n\n";
}

int GetSum(int* array, const int size) {
	int sum = 0;
	for (size_t i = 0; i < size; i++) {
		if ((array[i]) < 10 && (array[i]) > (-10) ) {
			sum += array[i];
		}
	}
	return sum;
}

void numberGreaterNext(int* array, const int size) {
	for (size_t i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) {
			cout << "[" << i << "] ";
		}
	}
	cout << "\n\n";
}

void multiplyАllmultiplesThrebyThirdElement(int* array, const int size , const int k) {

	for (size_t i = 0; i < size; i++) {
		if (array[i] > 0 && array[i + 1] > 0 || array[i] < 0 && array[i + 1] < 0) {
			if ((array[i] * array[i + 1]) < k ) {

				cout << "array[" << i << "] = " << array[i] << " | " << "array[" << i + 1 << "] = " << array[i + 1] << "\n";
			}
	
			
		}
	}
}
