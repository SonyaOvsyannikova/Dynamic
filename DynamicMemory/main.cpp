
#include <iostream>
#include <time.h>
#include <random>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
/*eсть массив 'arr' из 10-ти элементов, заполненный случайными числами. Нужно создать еще два массива 'even' и 'odd' минимально возможного размера, в массив 'even' нужно скопировать все четные значения из исходного массива, а в массив
'odd' - нечетные. Массивы 'even' и 'odd' вывести на экран.*/

// прототипы функций выносятся в заголовочные файлы

#include "FillRand.h"

#include "Print.h"
#include "Arrays1.h"

#include "Arrays2.h"




//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

int main()
{
	setlocale(LC_ALL, "ru");
#ifdef DYNAMIC_MEMORY_1
	int n = 0;
	cout << "введите количество элементов массива" << endl;
	cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	print(arr, n);
	int value;
	cout << "введите добавляемое значение" << endl;
	cin >> value;
	push_back(arr, n, value);
	print(arr, n);

	cout << endl;

	cout << "введите добавляемое значение" << endl;
	cin >> value;
	push_front(arr, n, value);
	print(arr, n);


	cout << "удаление последнего элемента" << endl;
	pop_back(arr, n);
	print(arr, n);

	cout << "удаление нулевого элемента" << endl;
	pop_front(arr, n);
	print(arr, n);

	cout << "функция erase удаление элемента по выбранному индексу " << endl;
	erase(arr, n);
	print(arr, n);

	cout << "функция insert удаление элемента по выбранному индексу " << endl;
	insert(arr, n);
	print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	


	int m; // количество строк
	int n; // количетво элементов строки
	cout << "введите количество строк  "; cin >> m;
	cout << "введите количество элементов строки  "; cin >> n;

	// создаем массив указателей

	int** arr = new int* [m];

	// выделяем память под строки двумерного массива

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}

	/* cout << "Память выделена " << endl;
	 system("pause");*/

	FillRand(arr, m, n);
	print(arr, m, n);

	cout << "Добавление строки в конец массива " << endl;
	push_row_back(arr, m, n);
	cout << "Добавление строки в начало массива " << endl;
	push_row_front(arr, m, n);
	print(arr, m, n);

	cout << "Добавление столбца в конец массива " << endl;
	push_col_back(arr, m, n);
	print(arr, m, n);

	//удаление думерного динамическго массива

	//1) удаление строк
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}

	// удаление массива указателей
	delete[] arr;
#endif // DYNAMIC_MEMORY_2


#ifdef DEBUG_ARRAYS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	print(arr, n);
#endif // DEBUG_ARRAYS


}
// реализации выносят в cpp файлы










/*for (int i = 0; i < q; i++)
{
	buffer[q] = a;
}

for (int j = q; q < n; j++)
{
	buffer[j] = arr[j + 1];
}
*/