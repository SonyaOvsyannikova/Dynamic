#include <iostream>
#include <time.h>
#include <random>
#include "Print.h"
using namespace std;
#include "Arrays2.h"
void push_row_back(int**& arr, int& m, const int n)
{
	//  1) ������� �������� ������
	int** buffer = new int* [m + 1];
	/*for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};
	}*/

	// 2) �������� ��� �������� ��������� ������� � ��������
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < m; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i];
	}
	// 3) ������� ��������� ������
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	// �� ����� ������� ������, ���������� ������� ������ ����������������
	delete[] arr;

	// 4) �������������� ����� ������ (������ ����������)
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
	//��������� ����� �� ����� ������
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
	// �������� �� ������� � �������������� ������ ������
	for (int i = 0; i < m; i++)
	{
		//1) ������� ������ ������� �������
		int* buffer = new int[n + 1]{};
		//2) �������� �������� ������ � ����� ������
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}

		//3)������� �������� ������
		delete[] arr[i];

		//4) ��������� ����� ������ ������ ������� �����
		arr[i] = buffer;
	}

	// 6) ����� ����, ��� �� �������������� ������ ������, ����������� ���������� ����� �� �������
	n++;
}



void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	//��� ����, ����� ������� ������� �� ������� � �������� ������ ����� ����������� ��� �������� ����� ����������
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

/*������� ������� �� ������� �� ��������� �������*/


//�������� 




