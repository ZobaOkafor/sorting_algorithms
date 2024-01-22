#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}


/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}


/**
 * swap - swaps the elements of the list
 * @ptr1: first pointer
 * @ptr2: second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 *
 */

void swap(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *aux, *tmp;

	aux = *ptr1;
	tmp = *ptr2;

	aux->next = tmp->next;
	tmp->prev = aux->prev;

	if (tmp->next)
		tmp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = tmp;

	aux->prev = tmp;
	tmp->next = aux;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = aux;
}
