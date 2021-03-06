// Algorithms.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "header.h"
#include "Point.h"

int main()
{
	try 
	{
		//bubbleSort
		{
			//best
			int a1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			//average
			int r1[100];
			setRandomValue(r1, 100);
			bubbleSort(r1, 100);
			cout << "Bubble: " << isSorted(r1, 100) << '\n';
			//worst
			int a2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

			bubbleSort(a1, 10);
			bubbleSort(a2, 10);
		}

		//choiceSort
		{
			//best
			int b1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			//average
			int r2[100];
			setRandomValue(r2, 100);
			choiceSort(r2, 100);
			cout<<"Choice :" << isSorted(r2, 100) << '\n';

			//worst
			int b2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

			choiceSort(b1, 10);
			choiceSort(b2, 10);
		}

		//insertionSort
		{
			//best
			int c1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			//average
			int r3[100];
			setRandomValue(r3, 100);
			insertionSort(r3, 100);
			cout << "Insertion: " << isSorted(r3, 100) << '\n';

			//worst
			int c2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

			insertionSort(c1, 10);
			insertionSort(c2, 10);
		}

		//countingSort
		{
			//best
			int d1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			//average
			int r4[100];
			setRandomValue(r4, 100);
			countingSort(r4, 100);
			cout << "Counting: " << isSorted(r4, 100) << '\n';

			//worst
			int d2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

			countingSort(d1, 10);
			countingSort(d2, 10);
		}

		//lsdradixSort
		{
			//best
			unsigned int d1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			//average
			for (int i = 0; i < 2; i++) {
				unsigned int r4[100];
				setRandomValue(r4, 100);
				lsdRadixSort(r4, 100);
				cout << "Radix lsd: " << isSorted(r4, 100) << '\n';
			}

			//worst
			unsigned int d2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

			lsdRadixSort(d1, 10);
			lsdRadixSort(d2, 10);
		}


		return 0;
	}
	catch (const char *error)
	{
		cout << error << '\n';
	}
}

