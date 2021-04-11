#include <iostream>
#include <time.h>
#include <random>
#include "FillRand.h"
using namespace std;
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