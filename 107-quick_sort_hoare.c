#include "sort.h"


/**
 * swap_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}


/**
 * partition_hoare - Order a subset of an array of integers
 * according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */

int partition_hoare(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1;
	int j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap_integers(&array[i], &array[j]);
			print_array(array, size);
		}
		else
		{
			return (j);
		}
	}
}



/**
 * sort_hoare - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */

void sort_hoare(int *array, size_t size, int left, int right)
{
	int part;

	if (right > left)
	{
		part = partition_hoare(array, size, left, right);
		sort_hoare(array, size, left, part - 1);
		sort_hoare(array, size, part + 1, right);
	}
}



/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_hoare(array, size, 0, size - 1);
}
