
#include <iostream>
#include <time.h>
#include <random>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
/*eсть массив 'arr' из 10-ти элементов, заполненный случайными числами. Нужно создать еще два массива 'even' и 'odd' минимально возможного размера, в массив 'even' нужно скопировать все четные значения из исходного массива, а в массив
'odd' - нечетные. Массивы 'even' и 'odd' вывести на экран.*/

void FillRand(int arr[], int n);
void FillRand(int** arr, const int m, const int n);

void print(int arr[], int n);
void print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n);

void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n);



void push_col_back(int** arr, const int m, int& n);


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

void FillRand(int* arr, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 20;
	}

}
void FillRand(int** arr, const int m, const int n)
{
	// использование двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 1 + rand() % 100;
		}

	}


}
void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void push_back(int*& arr, int& n, int value)
{
	// 1) создаем буферны массив нужного размера
	int* buffer = new int[n + 1]{};
	// 2) копируем все значения из одного массва в другой 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}
	// 3) После того как данные скопированы, удаляем исходный массв
	delete[] arr;
	//4) подменяем адрес указателя на исходный массив
	arr = buffer;
	//5) И только после всего этого можно записать новое значение а конец массива
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		// копируем элементы со смещением на один элемент вправо
		buffer[i + 1] = arr[i];

	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void push_row_back(int**& arr, int& m, const int n)
{
	//  1) создаем буферный массив
	int** buffer = new int* [m + 1];
	/*for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};
	}*/

	// 2) копируем все значения исходного массива в буферный
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < m; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i];
	}
	// 3) удаляем иссходный массив
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	// не нужно удалять строки, достаточно удалить старый массивуказателей
	delete[] arr;
	
	// 4) переопределить новый массив (массив указателей)
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
}

void push_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	//подменяем адрес на новый массив
	arr = buffer;
	arr[0] = new int[n] {};
	m++;

}

/*void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[] = arr[i];
	}
	delete[] arr;
	arr=buffer
}
*/


void push_col_back(int** arr, const int m, int& n)
{
	// проходим по строкам и переопределяем каждую строку
	for (int i = 0; i < m; i++)
	{
		//1) создаем строку нужного размера
		int* buffer = new int[n + 1]{};
		//2) копируем исходную строку в новую строку
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}

		//3)удаляем исходную строку
		delete[] arr[i];

		//4) подменяем адрес старой строки адресом новой
		arr[i] = buffer;
	}

	// 6) После того, как мы переопределили каждую строку, увеличиваем количество строк на единицу
	n++;
}



void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	//для того, чтобы удалить элемент из массива в буферный массив нужно скопировать все элементы кроме удаляемого
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;


}

void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}

/*Удаляет элемент из массива по заданному индексу*/

void erase(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	int a;
	cout << "введите номер элемента для удаления" << endl;
	cin >> a;
	for (int i = 0, j = 0; i < n; j++, i++)
	{
		if (i != (a - 1))
		{
			buffer[j] = arr[i];
		}
		else
		{
			j--;
		}

	}
	n--;
	delete[] arr;
	arr = buffer;
}

//добавить 
void insert(int*& arr, int& n)
{
	int* buffer = new int[n + 1]{};
	int q;
	cout << "введите индекс для добавления числа" << endl;
	cin >> q;
	int a;
	cout << "введите число которое вы хотите вставить" << endl;
	cin >> a;
	for (int i = 0; i < q; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[q] = a;

	for (int j = q; j < n; j++)
	{
		buffer[j + 1] = arr[j];
	}

	delete[] arr;
	arr = buffer;
	n++;
}








/*for (int i = 0; i < q; i++)
{
	buffer[q] = a;
}

for (int j = q; q < n; j++)
{
	buffer[j] = arr[j + 1];
}
*/