#include <iostream>
#include <time.h>
#include <random>
#include "Print.h"
using namespace std;
#include "Arrays2.h"
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
		buffer[i + 1] = arr[i];
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


//добавить 




