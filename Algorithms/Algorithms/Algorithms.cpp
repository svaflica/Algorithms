// Algorithms.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "header.h"
#include <iostream>

using namespace std;

int main()
{
	//bubbleSort

	//best
	int a1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//worst
	int a2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	bubbleSort(a1, 10);
	bubbleSort(a2, 10);

	//insertionSort

	//best
	int b1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//worst
	int b2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	choiceSort(b1, 10);
	choiceSort(b2, 10);

	//insertionSort

	//best
	int c1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//worst
	int c2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	insertionSort(c1, 10);
	insertionSort(c2, 10);

    return 0;
}

