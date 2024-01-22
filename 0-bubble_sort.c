#include "sort.h"


/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;
	int swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				swapped = 1;
				if (swapped)
					print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
