#include <iostream>
#define painters_basics // основы указателей
#define painters_and_arrays
/*
define -определять
definietion - определение
#define ИМЯ Значение
директива - это указание кампилятору на выполнение некоторых действий



*/
using namespace std;

/*указатели это переменная которая содержит адрес другой переменной (массива или функции)
адрес оперативной памяти - это число. которое занимает 4 байтов??
фсб свяывает центральный процессор и его можно поделить на две части
датабасс (64 бита)
& это оператор взятия адреса (addres of operator)
унарный оператор, который возвращает адрес своего операнда
* это оператор разыменования (dereferrence operator)
* возвращает значение по адресу
* объявляемая переменная указатель

*/

#define PI 3.14
int main()
{
    setlocale(LC_ALL, "ru");
#if defined painters_basics;
    int a = 2; // объявление переменной
    int* pa = &a; //объявление указателя
    cout << a << endl; // выводим на экран значение перемнной а
    cout << &a << endl; // выводим на экран значение перемнной а
    cout << &pa << endl; // выводим на экран значение перемнной а
    cout << *pa << endl; // разыменовываем указатель

    int* pb;
    int b = 3;
    pb = &b;
    cout << b << endl;
    cout << *pb << endl;
    cout << PI << endl;
#endif // painters_basics;

#if defined painters_and_arrays

    /*name massiv = addres
    Используя арифметику указателей можно вычислть адресс любого элемента масива
    ----------------------------------------------------------------------------
                        Арифметика указателей
    компилятор всегда долен знать на какой тип данных указывает указатель
    это нужно для того чтобы понимать сколько байт памяти нужно считать ил записать по адресу
    также это нужно ля арифметики указателей
    результат операции будет зависеть от типа данных на который указывает указатель
    например если указателю на char, прибавить единицу то адрес измениться на 1 байт
    если к указателю  int прибавить единицу , то на 4 байта изменится
    добл 8 байт

    */
    const int n = 5;
    int arr[n] = { 3,5,8,13,21 };
    cout << *arr << endl;
    for (int i = 0; i < n; i++)
    {
        // обращение к элементам массва через арифметику указателей и оепратор разыменования
        cout << *(arr + i) << endl;
        /*
        Доступ к элементам массива осущетствляется за константное время посколько сводятся у операции сложения, а операця сложения всегда выполняется за константное время
        то есть процессор на операцию сложения всегда тратит
        [] оператор индексирования, также высилет адрес элемента массива и разыменовывает его
        */
    }

#endif

}

