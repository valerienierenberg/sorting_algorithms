#include "deck.h"

/**
* sort_deck - sorts a deck of cards
* @deck: deck of carts
*
* Return: void
*/

void sort_deck(deck_node_t **deck)
{
    int i;

    for(i = 0; i <= 51; i++)
    {
        qsort(i, i, sort_deck, (size_t)deck);
    }
}
