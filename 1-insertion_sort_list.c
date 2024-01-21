#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: A double pointer to the head of the doubly linked list.
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* skip empty lists or one-element lists */

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		tmp = current->prev;
		while (tmp != NULL && current->n < tmp->n)
		{
			if (tmp->prev != NULL)
				tmp->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = tmp;

			tmp->next = current->next;
			current->prev = tmp->prev;
			current->next = tmp;
			tmp->prev = current;

			print_list((const listint_t *)*list);

			tmp = current->prev;
		}
		current = next;
	}
}
