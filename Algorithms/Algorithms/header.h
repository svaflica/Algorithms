#pragma once
#include <ctime>
#include <iostream>

using namespace std;


//helpFunctions

//is used in radixSort
int digit(unsigned int value, int i)
{
	while (i > 1)
	{
		value /= 10;
		i--;
	}

	return (value % 10);
}


//is used in countingSort
int maxValue(const unsigned int *array, int length)
{
	if (length < 1)
		throw "Wrong length";

	unsigned int max = array[0];

	for (int i = 1; i < length; i++)
		if (max < array[i])
			max = array[i];

	return max;
}

//is used in radixSort
int radix(unsigned int num)
{
	if (num == 0)
		return 1;

	int check = 0;
	while (num > 0)
	{
		num /= 10;
		check++;
	}

	return check;
}


template <class Type>
bool isSorted(Type *array, int length)
{
	for (int i = 1; i < length; i++)
		if (array[i] < array[i - 1])
			return false;

	return true;
}


//sortings
template <class Type>
void bubbleSort(Type *array, int length)
{
	if (isSorted(array, length))
		return;

	if (length < 1)
		throw "Wrong length";

	Type temp;

	for (int i = 0; i < length; i++)
		for (int j = i + 1; j < length; j++)
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}


template <class Type>
void choiceSort(Type *array, int length)
{
	if (isSorted(array, length))
		return;

	if (length < 1)
		throw "Wrong length";

	Type min;
	int pos;

	for (int i = 0; i < length; i++) {
		pos = i;
		min = array[i];

		for (int j = i + 1; j < length; j++)
		{
			if (array[j] < min)
			{
				pos = j;
				min = array[j];
			}
		}
		array[pos] = array[i];
		array[i] = min;
	}
}


template <class Type>
void insertionSort(Type *array, int length)
{
	if (isSorted(array, length))
		return;

	if (length < 1)
		throw "Wrong length";

	Type key;

	for (int i = 1, j; i < length; ++i)
	{
		key = array[i];
		for (j = i - 1; j >= 0 && array[j] > key; --j)
			array[j + 1] = array[j];
		array[j + 1] = key;
	}
}


void countingSort(unsigned int *array, int length)
{
	if (isSorted(array, length))
		return;


	int lengthSort = maxValue(array, length);
	unsigned int *arraySort = new unsigned int[lengthSort + 1];

	for (int i = 0; i <= lengthSort; i++)
		arraySort[i] = 0;

	for (int i = 0; i < length; i++)
	{
		arraySort[array[i]]++;
	}

	for (int i = 0; i <= lengthSort; i++)
	{
		while (arraySort[i] > 0)
		{
			*array = i;
			*array++;
			arraySort[i]--;
		}
	}

	delete[] arraySort;
}

//ya dolbilsya s etim algorithmom 5 chasov
//ya tak i ne ponyal, poetomu spisal u tebya
//a esche ono ne robit ._.
void lsdRadixSort(unsigned int* array, int length) 
{
		if (isSorted(array, length))
			return;

		int maxRadix = radix(maxValue(array, length));

		// Sorting
		int j, k, d;
		int* arraySort = new int[2];
		int* arrayResult = new int[length];

		for (int i = 0; i < maxRadix; ++i)
		{
			// counting bits
			arraySort[0] = 0;
			arraySort[1] = 0;
			for (j = 0; j < length; ++j)
				arraySort[(array[j] >> i) & 1]++;

			// sort order
			arraySort[1] = arraySort[0];
			arraySort[0] = 0;

			// put in order by current bit
			for (j = 0; j < length; ++j)
			{
				d = (array[j] >> i) & 1;
				arrayResult[arraySort[d]] = array[j];
				arraySort[d]++;
			}

			// copying
			for (j = 0; j < length; ++j)
				array[j] = arrayResult[j];
		}

		delete[] arrayResult;
		delete[] arraySort;
}

//ya esche ne gotov k etomu der'mu
//void msdRadixSort


//for tests
void setRandomValue(int* array, int length)
{
	if (length < 1)
		throw "Wrong length";

	srand(time(nullptr));

	for (int i = 0; i < length; ++i)
		array[i] = rand() % 1000 - 500;
}


void setRandomValue(unsigned int* array, int length)
{
	if (length < 1)
		throw "Wrong length";

	srand(time(nullptr));

	for (int i = 0; i < length; ++i)
		array[i] = rand() % 1000;
}


template <class Type>
void arrayOutput(Type *array, int length)
{
	cout << "--------------------------\n";
	for (int i = 0; i < length; i++)
		cout << array[i] << '\n';
	cout << "--------------------------\n";
}