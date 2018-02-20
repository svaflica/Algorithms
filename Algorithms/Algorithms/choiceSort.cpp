#include "header.h"

template <class type>
type& choiceSort(const type *array, int length)
{
	type min;

	for (int i = 0; i < length; i++) {
		min = array[i];

		for (int j = i; j < length; j++)
			if (min > array[j])
				min = array[j];

		array[j] = array[i];
		array[i] = min;
	}

	return array;
}