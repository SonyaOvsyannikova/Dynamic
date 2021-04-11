#include <iostream>
#include <time.h>
#include <random>
#include "Print.h"
using namespace std;
#include "Arrays1.h"
void push_back(int*& arr, int& n, int value)
{
	// 1) ������� ������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	// 2) �������� ��� �������� �� ������ ������ � ������ 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}
	// 3) ����� ���� ��� ������ �����������, ������� �������� �����
	delete[] arr;
	//4) ��������� ����� ��������� �� �������� ������
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		// �������� �������� �� ��������� �� ���� ������� ������
		buffer[i + 1] = arr[i];

	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
void insert(int*& arr, int& n)
{
	int* buffer = new int[n + 1]{};
	int q;
	cout << "������� ������ ��� ���������� �����" << endl;
	cin >> q;
	int a;
	cout << "������� ����� ������� �� ������ ��������" << endl;
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
void erase(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	int a;
	cout << "������� ����� �������� ��� ��������" << endl;
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
