#include <string.h>
#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * compare_cards - Compare two cards for sorting.
 * @a: First card.
 * @b: Second card.
 * Return: Integer less than, equal to, or greater than zero if a is found,
 *         respectively, to be less than, to match, or be greater than b.
 */
static int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;

    if (card_a->kind == card_b->kind)
        return strcmp(card_a->value, card_b->value);

    return card_a->kind - card_b->kind;
}

/**
 * sort_deck - Sort a deck of cards.
 * @deck: A pointer to the head of the deck.
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



void print_deck(const deck_node_t *deck)
{
    size_t i;
    char kinds[4] = {'S', 'H', 'C', 'D'};

    i = 0;
    while (deck)
    {
        if (i)
            printf(", ");
        printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
        if (i == 12)
            printf("\n");
        i = (i + 1) % 13;
        deck = deck->next;
    }
}

deck_node_t *init_deck(const card_t cards[52])
{
    deck_node_t *deck;
    deck_node_t *node;
    size_t i;

    i = 52;
    deck = NULL;
    while (i--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        node->card = &cards[i];
        node->next = deck;
        node->prev = NULL;
        if (deck)
            deck->prev = node;
        deck = node;
    }
    return (deck);
}

int main(void)
{
    card_t cards[52] = {
        {"Jack", CLUB}, {"4", HEART}, {"3", HEART}, {"3", DIAMOND}, {"Queen", HEART}, {"5", HEART}, {"5", SPADE}, {"10", HEART}, {"6", HEART}, {"5", DIAMOND}, {"6", SPADE}, {"9", HEART}, {"7", DIAMOND}, {"Jack", SPADE}, {"Ace", DIAMOND}, {"9", CLUB}, {"Jack", DIAMOND}, {"7", SPADE}, {"King", DIAMOND}, {"10", CLUB}, {"King", SPADE}, {"8", CLUB}, {"9", SPADE}, {"6", CLUB}, {"Ace", CLUB}, {"3", SPADE}, {"8", SPADE}, {"9", DIAMOND}, {"2", HEART}, {"4", DIAMOND}, {"6", DIAMOND}, {"3", CLUB}, {"Queen", CLUB}, {"10", SPADE}, {"8", DIAMOND}, {"8", HEART}, {"Ace", SPADE}, {"Jack", HEART}, {"2", CLUB}, {"4", SPADE}, {"2", SPADE}, {"2", DIAMOND}, {"King", CLUB}, {"Queen", SPADE}, {"Queen", DIAMOND}, {"7", CLUB}, {"7", HEART}, {"5", CLUB}, {"10", DIAMOND}, {"4", CLUB}, {"King", HEART}, {"Ace", HEART},
    };
    deck_node_t *deck;

    deck = init_deck(cards);
    print_deck(deck);
    printf("\n");
    sort_deck(&deck);
    printf("\n");
    print_deck(deck);
    return (0);
}
