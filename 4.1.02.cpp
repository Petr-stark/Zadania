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
void randomDigits(int* array, const int  size, const int LOW_BOUND, const int UP_BOUND);

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
void print(int* array, const int size);

/**
* \brief Поиск числа состоящих из одной цифры.
* \param array Массив
* \param size Размер массива
* \param return Значение суммы
**/
bool isOneDigit(int number);

/**
* \brief Сумма элементов массива, состоящих из одной цифры.
* \param array Массив
* \param size Размер массива
* \param return Значение суммы
**/
int getSum(int* array, const size_t size);

int findMax(const int* array, size_t size);

int findMin(const int* array, size_t size);

/**
* \brief Перестановка элементов массива местами.
* \param array Массив
* \param size Размер.
**/
void replacementOfElements(int* array, const size_t size);

int getNumber();

/**
* \brief Поиск номера последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа.
* \param array Массив
* \param size Размер.
**/
int getNumberOfLastPair(int* array, const size_t size);

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
int main()
{
	setlocale(LC_ALL, "ru");

	const int LOW_BOUND = -100;
	const int UP_BOUND = 100;

	cout << "Введите количество элементов массива: ";
	int* array;
	int size;
	cin >> size;

	array = new int[size];
	cout << "1)Сгенерировать массив\n" << "2)Заполнить массив вручную\n" << "1 или 2: ";
	int choice;
	cin >> choice;

	const auto filling = static_cast<Filling>(choice);
	switch (filling)
	{
	case Filling::RANDOM:
		randomDigits(array, size, LOW_BOUND, UP_BOUND);
		print(array, size);
		break;
	case Filling::USER:
		userInput(array, size);
		print(array, size);
		break;
	default:
		cout << "Ошибка! Не выбран ни один из вариантов";
	}

	cout << "Сумма элементов, значения которых состоят из одной цифры = " << getSum(array, size) << "\n\n";// 1

	replacementOfElements(array, size);

	cout << "Номер последней пары с одинаковыми знаками, произведение которых меньше заданного числа = " << getNumberOfLastPair(array, size) << "\n\n"; // 3

	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}


	return 0;
}

// Заполнение массива случайными числами
void randomDigits(int* array, const int  size, const int LOW_BOUND, const int UP_BOUND)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % (2 * UP_BOUND + 1) + LOW_BOUND;
	}
}

// Ввод массива с клавиатуры
void userInput(int* array, const int  size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> array[i];
	}
}

// Вывод массива
void print(int* array, const int size)
{
	cout << "array[" << size << "]" << "= {";
	for (int i = 0; i < size - 1; i++)
	{
		cout << array[i] << ";" << setw(3);
	}
	cout << array[size - 1] << "}\n\n";
}

// Поиск числа состоящего из одной цифры(1)
bool isOneDigit(int number)
{
	size_t counter = 0;
	unsigned absNumber = abs(number);

	while (absNumber >= 1)
	{
		absNumber = absNumber / 10;
		counter++;
	}

	return counter == 1;
}

// Сумма элементов, значения которых состоят из одной цифры(1)
int getSum(int* array, const size_t size)
{
	int sum = 0;

	for (size_t i = 0; i < size; i++)

		if (isOneDigit(array[i]))
		{
			sum += array[i];
		}

	return sum;
}

int findMin(const int* array, size_t size)
{
	int min = 0;
	for (size_t i = 0; i < size; i++)
		if (array[min] > array[i])
			min = i;

	return min;
}

int findMax(const int* array, size_t size)
{
	int max = 0;
	for (size_t i = 0; i < size; i++)
		if (array[max] < array[i])
			max = i;

	return max;
}

// Заменить элементы массива между минимальным и максимальным на те же элементы в обратном порядке(2)
void replacementOfElements(int* array, const size_t size)
{

	int min = findMin(array, size), max = findMax(array, size), first, second;

	if (min < max)
	{
		first = min;
		second = max;
	}
	else
	{
		first = max;
		second = min;
	}

	int* invertedArray = new int[size];
	int index = 0;

	for (size_t i = 0; i < first; i++)
	{
		invertedArray[index++] = array[i];
	}
	for (size_t i = second; i >= first; i--)
	{
		invertedArray[index++] = array[i];
	}
	for (size_t i = second + 1; i < size; i++)
	{
		invertedArray[index++] = array[i];
	}

	print(invertedArray, size);

	if (invertedArray != nullptr)
	{
		delete[] invertedArray;
		invertedArray = nullptr;
	}


}// Конец (2)

int getNumber()
{
	int k;
	cout << "\nВведите число, которое будет значением произведения пар = ";
	cin >> k;

	return k;
}

// Поиск номера последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа(3)
int getNumberOfLastPair(int* array, const size_t size)
{
	int k = getNumber();

	size_t number = 0;

	for (size_t i = 0; i < size - 1; i++)

	{
		if (array[i] * array[i + 1] > 0)
		{
			if (array[i] * array[i + 1] < k)

			{
				number = i;
			}
		}

	}

	return number;
}