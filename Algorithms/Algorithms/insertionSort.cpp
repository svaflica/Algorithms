#include "header.h"

template <class type>
type& insertionSort(const type *array, int length)
[
	type key;
	int i;

	for (int j = 2; j < length; j++)
	{
		key = array[j];
		i = j - 1;
		while (i > 0 && array[i] > key)
			i--;

		array[i + 1] = key;
	}

	return array;
]
