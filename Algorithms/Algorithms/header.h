#pragma once
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;


//helpFunctions

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

//is used in radixSort
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


int digit(unsigned int num, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		num /= 10;
	}

	return num % 10;
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


void lsdRadixSort(unsigned int array[], const int length)
{
	unsigned int maxVal = maxValue(array, length);

	unsigned int *output = new unsigned int[length];
	int i, count[10];

	for (int exp = 1; maxVal / exp > 0; exp *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;

		// Store count of occurrences in count[]
		for (i = 0; i < length; i++)
			count[(array[i] / exp) % 10]++;

		// Change count[i] so that count[i] now contains actual
		//  position of this digit in output[]
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// Build the output array
		for (i = length - 1; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		// Copy the output array to arr[], so that arr[] now
		// contains sorted numbers according to current digit
		for (i = 0; i < length; i++)
			array[i] = output[i];
	}

	delete[] output;
}


void msdRadixSort(unsigned int *array, int length)
{
	unsigned int maxLength = radix(maxValue(array, length));

	unsigned int *output = new unsigned int[length];
	int j, count[10];

	for (int i = maxLength; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;

		// Store count of occurrences in count[]
		for (j = 0; j < length; j++)
			count[digit(array[j], i)]++;

		// Change count[i] so that count[i] now contains actual
		//  position of this digit in output[]
		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];

		// Build the output array
		for (j = length - 1; j >= 0; j--)
		{
			output[count[digit(array[j], i)] - 1] = array[j];
			count[digit(array[j], i)]--;
		}

		// Copy the output array to arr[], so that arr[] now
		// contains sorted numbers according to current digit
		for (j = 0; j < length; j++)
			array[j] = output[j];
	}

	delete[] output;

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