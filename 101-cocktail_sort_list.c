#include "sort.h"

/**
* cocktail_sort_list - sorts a doubly linked list of integers in
*                       ascending order using the cocktail sort algorithm
* @list: linked list to be sorted
*
* Return: void
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	for (; current != NULL; current = current->next)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
	}
}
