#include <iostream>
using namespace std;

#define tab "\t"

void Exchange(int& a, int& b); // прототип функцииб объявление функции. function  declaration

void main()
{
	setlocale(LC_ALL, "ru");
	int a = 2;
	int b = 3;
	cout << a << tab << b << endl;
	Exchange(a, b);
	cout << a << tab << b << endl;
}

void Exchange(int& a, int& b)
{
	int c = a; // контейнер
	a = b;
	b = c;
}