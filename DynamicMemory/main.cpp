
#include <iostream>
#include <time.h>
#include <random>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
/*e��� ������ 'arr' �� 10-�� ���������, ����������� ���������� �������. ����� ������� ��� ��� ������� 'even' � 'odd' ���������� ���������� �������, � ������ 'even' ����� ����������� ��� ������ �������� �� ��������� �������, � � ������
'odd' - ��������. ������� 'even' � 'odd' ������� �� �����.*/

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
	// ������������� ���������� ������������� �������
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
		buffer[i+1] = arr[i];
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

//�������� 
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








/*for (int i = 0; i < q; i++)
{
	buffer[q] = a;
}

for (int j = q; q < n; j++)
{
	buffer[j] = arr[j + 1];
}
*/