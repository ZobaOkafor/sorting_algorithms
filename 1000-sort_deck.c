#include "deck.h"


/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 is greater than s2
 * 0 if s1 is equal to s2
 * Negative byte difference if s1 is less than s2
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}


/**
 * compare_cards - Compare two cards for sorting.
 * @a: First card.
 * @b: Second card.
 *
 * Return: Integer less than, equal to, or greater than zero if a is found,
 * respectively, to be less than, to match, or be greater than b.
 */

int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;

	if (card_a->kind == card_b->kind)
		return (_strcmp(card_a->value, card_b->value));

	return (card_a->kind - card_b->kind);
}



/**
 * sort_deck - Sort a deck of cards.
 * @deck: A pointer to the head of the deck.
 *
 */

void sort_deck(deck_node_t **deck)
{
	size_t i;
	deck_node_t **nodes;

	if (deck == NULL || *deck == NULL)
		return;

	nodes = malloc(sizeof(deck_node_t *) * 52);
	if (nodes == NULL)
		return;

	for (i = 0; i < 52; ++i)
	{
		nodes[i] = *deck;
		*deck = (*deck)->next;
		if (*deck != NULL)
			(*deck)->prev = NULL;
	}

	qsort(nodes, 52, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < 51; ++i)
	{
		nodes[i]->next = nodes[i + 1];
		nodes[i + 1]->prev = nodes[i];
	}

	nodes[51]->next = NULL;
	*deck = nodes[0];

	free(nodes);
}
