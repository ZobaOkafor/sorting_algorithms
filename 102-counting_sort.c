#include "sort.h"


/**
 * counting_sort - Sorts an array of integers in ascending
 * order using Counting sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */

void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array, max, i, j;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max + 1);

	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}
	for (j = size - 1; j >= 0; j--)
	{
		output_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];

	free(output_array);
	free(count_array);
}
