#include "sort.h"


/**
 * sift_down - Perform sift-down operation on the heap.
 * @array: The array representing the heap.
 * @size: The size of the heap.
 * @start: The index to start the sift-down operation.
 * @end: The end index of the heap.
 */

void sift_down(int *array, size_t size, size_t start, size_t end)
{
	int tmp;
	size_t root = start;
	size_t child, swap;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		/* Swap elements and continue the sift-down operation */
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;

		print_array(array, size);

		root = swap;
	}
}



/**
 * heap_sort - Sort an array of integers in ascending order
 * using heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */

void heap_sort(int *array, size_t size)
{
	int i, tmp;
	size_t end;

	if (array == NULL || size < 2)
		return;

	/* Build the initial heap */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	/* Perform heap sort */
	for (end = size - 1; end > 0; end--)
	{
		/* Swap the root (maximum element) with the last element */
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;

		print_array(array, size);

		/* Perform sift-down on the reduced heap */
		sift_down(array, size, 0, end - 1);
	}
}
