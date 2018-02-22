// Algorithms.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "header.h"
#include <iostream>

using namespace std;

// Andrey insert
template<typename T>
void printArr(T* arr, int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
	//bubbleSort

	int a1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int a2[10] = { 9, -4, 3, 6, 10, 4, 3, 100, 1, 0 };

	bubbleSort(a1, 10);
	bubbleSort(a2, 10);

    printArr(a1, 10);
    printArr(a2, 10);

	//choiceSort

	//best
	int b1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//worst
	int b2[10] = { 9, -4, 3, 6, 10, 4, 3, 100, 1, 0 };

	choiceSort(b1, 10);
	choiceSort(b2, 10);

    printArr(b1, 10);
    printArr(b2, 10);


	//insertionSort

	//best
	int c1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//worst
	int c2[10] = { 9, -4, 3, 6, 10, 4, 3, 100, 1, 0 };

	insertionSort(c1, 10);
	insertionSort(c2, 10);

    printArr(c1, 10);
    printArr(c2, 10);

    return 0;
}

