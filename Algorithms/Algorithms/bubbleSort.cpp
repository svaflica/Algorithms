#include "header.h"

template <class type>
type& bubbleSort(const type *array, int length)
{
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length - i - 1; j++)
			if (array[j] > array[j + 1]) {

				type t = array[j];
				array[j] = array[i];
				array[i] = t;
			}

	return array;
}