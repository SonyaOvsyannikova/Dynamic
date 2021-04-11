
#include <iostream>
#include <time.h>
#include <random>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
/*e��� ������ 'arr' �� 10-�� ���������, ����������� ���������� �������. ����� ������� ��� ��� ������� 'even' � 'odd' ���������� ���������� �������, � ������ 'even' ����� ����������� ��� ������ �������� �� ��������� �������, � � ������
'odd' - ��������. ������� 'even' � 'odd' ������� �� �����.*/

// ��������� ������� ��������� � ������������ �����

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
	cout << "������� ���������� ��������� �������" << endl;
	cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	print(arr, n);
	int value;
	cout << "������� ����������� ��������" << endl;
	cin >> value;
	push_back(arr, n, value);
	print(arr, n);

	cout << endl;

	cout << "������� ����������� ��������" << endl;
	cin >> value;
	push_front(arr, n, value);
	print(arr, n);


	cout << "�������� ���������� ��������" << endl;
	pop_back(arr, n);
	print(arr, n);

	cout << "�������� �������� ��������" << endl;
	pop_front(arr, n);
	print(arr, n);

	cout << "������� erase �������� �������� �� ���������� ������� " << endl;
	erase(arr, n);
	print(arr, n);

	cout << "������� insert �������� �������� �� ���������� ������� " << endl;
	insert(arr, n);
	print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	


	int m; // ���������� �����
	int n; // ��������� ��������� ������
	cout << "������� ���������� �����  "; cin >> m;
	cout << "������� ���������� ��������� ������  "; cin >> n;

	// ������� ������ ����������

	int** arr = new int* [m];

	// �������� ������ ��� ������ ���������� �������

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}

	/* cout << "������ �������� " << endl;
	 system("pause");*/

	FillRand(arr, m, n);
	print(arr, m, n);

	cout << "���������� ������ � ����� ������� " << endl;
	push_row_back(arr, m, n);
	cout << "���������� ������ � ������ ������� " << endl;
	push_row_front(arr, m, n);
	print(arr, m, n);

	cout << "���������� ������� � ����� ������� " << endl;
	push_col_back(arr, m, n);
	print(arr, m, n);

	//�������� ��������� ������������ �������

	//1) �������� �����
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}

	// �������� ������� ����������
	delete[] arr;
#endif // DYNAMIC_MEMORY_2


#ifdef DEBUG_ARRAYS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	print(arr, n);
#endif // DEBUG_ARRAYS


}
// ���������� ������� � cpp �����










/*for (int i = 0; i < q; i++)
{
	buffer[q] = a;
}

for (int j = q; q < n; j++)
{
	buffer[j] = arr[j + 1];
}
*/