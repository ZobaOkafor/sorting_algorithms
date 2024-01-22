#include "sort.h"

/**
 * merge - Merges two subarrays into a single sorted array
 * @array: The array to be merged
 * @left: Start index of the left subarray
 * @mid: Middle index
 * @right: End index of the right subarray
 * @temp: Temporary array to store merged result
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
	size_t i, j, k;
	size_t size1 = mid - left + 1;
	size_t size2 = right - mid;

	printf("[left]: ");
	print_array(array + left, size1);
	printf("[right]: ");
	print_array(array + mid + 1, size2);
	for (i = 0; i < size1; i++)
		temp[i] = array[left + i];
	for (j = 0; j < size2; j++)
		temp[size1 + j] = array[mid + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while (i < size1 && j < size2)
	{
		if (temp[i] <= temp[j + size1])
		{
			array[k] = temp[i];
			i++;
		}
		else
		{
			array[k] = temp[j + size1];
			j++;
		}
		k++; }
	while (i < size1)
	{
		array[k] = temp[i];
		i++;
		k++; }
	while (j < size2)
	{
		array[k] = temp[j + size1];
		j++;
		k++; }
	printf("[Done]: ");
	print_array(array + left, size1 + size2);
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort
 * @array: The array to be sorted
 * @left: Start index of the array
 * @right: End index of the array
 * @temp: Temporary array to store merged result
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid, temp);
		merge_sort_recursive(array, mid + 1, right, temp);

		printf("Merging...\n");
		merge(array, left, mid, right, temp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merge_sort_recursive(array, 0, size - 1, temp);

	free(temp);
}
