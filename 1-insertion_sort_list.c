#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers in
*                       ascending order using the insertion sort algorithm
* @list: linked list to be sorted
*
* Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next; /* set 'current' to posit. of 2nd node of list */

	for (; current != NULL; current = current->next)
	{ /* ^ while current exists, traverse through current */
		while (current->prev != NULL && current->n < current->prev->n)
		{ /*
			* ^ as long as you are not already at the head of the list...
			* AND the value at your position is greater than the previous value
			*/
			current->prev->next = current->next;

			if (current->next != NULL) /* making sure we're not at the tail */
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

/*
* void insertion_sort_list(listint_t **list)
* {
*	int i;
*	listint_t *cur, *ptr, *tmp;
*	cur= *list;
*
*	if (cur->next==NULL)
*		return;
*
*	cur = cur->next;
*
*	while(cur != NULL)
*	{
*		i = 0;
*		ptr = cur;
*		tmp = cur->prev;
*		cur = cur->next;
*
*		while (tmp != NULL && tmp->n > ptr->n)
*		{
*			i++;
*			tmp = tmp->prev;
*		}
*
*		if (i)
*		{
*			ptr->prev->next = ptr->next;
*			if (ptr->next != NULL)
*			ptr->next->prev = ptr->prev;
*
*			if (tmp == NULL)
*			{
*				tmp = *list;
*				ptr->prev = NULL;
*				ptr->next = tmp;
*				ptr->next->prev = ptr;
*				*list = ptr;
*			}
*			else
*			{
*				tmp = tmp->next;
*				tmp->prev->next = ptr;
*				ptr->prev = tmp->prev;
*				tmp->prev = ptr;
*				ptr->next = tmp;
*			}
*			print_list(*list);
*		}
*	}
*}
*/
