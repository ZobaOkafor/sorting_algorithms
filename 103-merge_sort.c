#include "sort.h"


/**
 * merge_sub_array - Merge two sorted sub arrays into
 * a single sorted sub array.
 * @sub_array: The original array containing two sorted sub arrays.
 * @buff: A buffer to store the merged result.
 * @front: The starting index of the first sub array.
 * @middle: The ending index of the first sub array.
 * @back: The ending index of the second sub array.
 *
 */

void merge_sub_array(int *sub_array, int *buff, size_t front, size_t middle,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + front, middle - front);

	printf("[right]: ");
	print_array(sub_array + middle, back - middle);

	for (i = front, j = middle; i < middle && j < back; k++)
		buff[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < middle; i++)
		buff[k++] = sub_array[i];
	for (; j < back; j++)
		buff[k++] = sub_array[j];
	for (i = front, k = 0; i < back; i++)
		sub_array[i] = buff[k++];

	printf("[Done]: ");
	print_array(sub_array + front, back - front);
}


/**
 * merge_sort_recursive - Implement the merge sort algorithm
 * through recursion.
 * @sub_array: An array to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The starting index of the sub array.
 * @back: The ending index of the sub array.
 */

void merge_sort_recursive(int *sub_array, int *buff, size_t front,
		size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(sub_array, buff, front, middle);
		merge_sort_recursive(sub_array, buff, middle, back);
		merge_sub_array(sub_array, buff, front, middle, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
