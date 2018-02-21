#pragma once

template <class type>
void bubbleSort(type *array, int length)
{
	if (isSorted(array, length) == false) {
		type temp;

		for (int i = 0; i < length; i++)
			for (int j = 1; j < length; j++) {

				if (array[j] < array[j - 1]) {
					temp = array[j];
					array[j] = array[i];
					array[i] = temp;
				}
			}
	}
}


template <class type>
void choiceSort(type *array, int length)
{
	if (isSorted(array, length) == false) {
		type min;
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
}


template <class type>
void insertionSort(type *array, int length)
{
	if (isSorted(array, length) == false) {
		type key;
		int i;


		for (int i = 1, j; i < length; ++i)
		{
			key = array[i];
			for (j = i - 1; j >= 0 && array[j] > key; --j)
				array[j + 1] = array[j];
			array[j + 1] = key;
		}
	}
}


void countingSort(int *array, int length);


void radixSort(int *array, int length);


//
int max(int *array, int length);


template <class type>
bool isSorted(type *array, int length)
{
	for (int i = 1; i < length; i++)
		if (array[i] < array[i - 1])
			return false;

	return true;
}