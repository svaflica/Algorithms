#pragma once

template <class type>
type& bubbleSort(type *array, int length)
{
	type temp;

	for (int i = 0; i < length; i++)
		for (int j = 1; j < length; j++) {

			if (array[j] < array[j - 1]) {
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}

	return *array;
}


template <class type>
type& choiceSort(type *array, int length)
{
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

	return *array;
}


template <class type>
type& insertionSort(type *array, int length)
{
	type key;
	int i;


	for (int i = 1, j; i < length; ++i)
	{
		key = array[i];
		for (j = i - 1; j >= 0 && array[j] > key; --j)
			array[j + 1] = array[j];
		array[j + 1] = key;
	}

	return *array;
}


int& countingSort(int *array, int length);


int& radixSort(int *array, int length);


//
int max(int *array, int length);
