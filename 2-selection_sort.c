#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, cur_min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		cur_min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[cur_min])
				cur_min = j;
		}

		if (cur_min != i)
		{
			tmp = array[i];
			array[i] = array[cur_min];
			array[cur_min] = tmp;

			print_array(array, size);
		}
	}
}
