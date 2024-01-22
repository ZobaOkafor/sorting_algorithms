#include "sort.h"


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


/**
 * liststart_sort - move the bigger numbers to the end
 * @ptr: pointer to the bigger number
 * @start: end of the list
 * @list: list of integers
 *
 */

void liststart_sort(listint_t **ptr, listint_t **start, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *start && aux->next != *start)
	{
		if (aux->n > aux->next->n)
		{
			swap(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}

	*start = aux;
	*ptr = aux;
}


/**
 * listend_sort - moves the smaller numbers to the start
 * @ptr: pointer to the smaller number
 * @end: start of the list
 * @list: list of integers
 *
 */

void listend_sort(listint_t **ptr, listint_t **end, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *end && aux->prev != *end)
	{
		if (aux->n < aux->prev->n)
		{
			swap(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}

	*end = aux;
	*ptr = aux;
}


/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: head of the linked list
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	start = end = NULL;
	ptr = *list;

	do {
		liststart_sort(&ptr, &start, list);
		listend_sort(&ptr, &end, list);
	} while (start != end);
}
