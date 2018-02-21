#include "header.h"
#include "stdafx.h"


int max(const int *array, int length)
{
	int max = array[0];

	for (int i = 1; i < length; i++)
		if (max < array[i])
			max = array[i];

	return max;
}


//now just for unnegative
int& countingSort(const int *array, int length)
{
	int lengthSort = max(array, length);
	int *arraySort = new int[lengthSort + 1];
	
	//To delete some musor
	for (int i = 0; i < lengthSort; i++)
		arraySort[i] = 0;

	for (int i = 0; i < length; i++)
		arraySort[array[i]]++;

	for (int i = 1; i < lengthSort; i++)
		arraySort[i] += arraySort[i - 1];

	int *arrayResult = new int[length];
	int index;
	for (int i = length - 1; i >= 0; i--) {
		//-1 because array starts with No 0
		index = --arraySort[array[i]];

		arrayResult[index] = array[i];
	}

	return *arrayResult;
}