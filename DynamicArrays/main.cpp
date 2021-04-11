#include <iostream>

using namespace std;
#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "введите размер " << endl;
	cin >> n;
	int* arr = new int[n] {};
	Print(arr, n);
	FillRand(arr, n);
	Print(arr, n);
	delete[] arr;
	cout << endl;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
	
}
void Print(int *arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}