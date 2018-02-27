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
int maxValue(const int *array, int length)
{
	if (length < 1)
		throw "Wrong length";

	int max = array[0];

	for (int i = 1; i < length; i++)
		if (max < array[i])
			max = array[i];

	return max;
}


int maxValue(const unsigned int *array, int length)
{
	if (length < 1)
		throw "Wrong length";

	int max = array[0];

	for (int i = 1; i < length; i++)
		if (max < array[i])
			max = array[i];

	return max;
}


//is used in countingSort
int minValue(const int *array, int length)
{
	if (length < 1)
		throw "Wrong length";

	int min = array[0];

	for (int i = 1; i < length; i++)
		if (min > array[i])
			min = array[i];

	return min;
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


void countingSort(int *array, int length)
{
	if (isSorted(array, length))
		return;


	int maxVal = maxValue(array, length);
	int minVal = minValue(array, length);

	int arraySortLength = maxVal - minVal + 1;
	int *arraySort = new int[arraySortLength];

	for (int i = 0; i < arraySortLength; i++)
		arraySort[i] = 0;

	for (int i = 0; i < length; i++)
		arraySort[array[i] - minVal]++;

	for (int i = 0; i < arraySortLength; i++)
	{
		while (arraySort[i] > 0)
		{
			*array = i + minVal;
			*array++;
			arraySort[i]--;
		}
	}

	delete[] arraySort;
}

//works only for arrays with less than 20 elements
//don't know, why
void lsdRadixSort(unsigned int *array, const int length)
{
	int i, count[10];
	unsigned int max, bucket[10], exponent = 1;

	max = maxValue(array, length);

	while (max / exponent > 0) {
		//reset count
		for (i = 0; i < 10; i++) {
			count[i] = 0;
		}

		//save count of the occurrence
		for (i = 0; i < length; i++) {
			count[(array[i] / exponent) % 10]++;
		}

		//set count to contain the actual position of the digits
		for (i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		//build the bucket
		for (i = length - 1; i >= 0; i--) {
			bucket[count[(array[i] / exponent) % 10] - 1] = array[i];
			count[(array[i] / exponent) % 10]--;
		}

		//copy the result to arr
		for (i = 0; i < length; i++) {
			array[i] = bucket[i];
		}

		exponent *= 10;
	}
}


void msdRadixSort(unsigned int *array, int length)
{
	
}

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