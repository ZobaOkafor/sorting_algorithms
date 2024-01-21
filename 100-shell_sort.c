#include "sort.h"


/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;
	size_t gap = 1;

	if (array == NULL || size < 2)
		return;

	/* Generate Knuth sequence for intervals (gap) */
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = tmp;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
