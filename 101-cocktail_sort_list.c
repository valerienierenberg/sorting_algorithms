#include "sort.h"

/**
* cocktail_sort_list - sorts a doubly linked list in ascending order
*               using the cocktail sort algorithm
* @list: doubly linked list to be sorted
*
* Return: void
*/

// Function to merge two linked lists 
listint_t *cocktailsort(listint_t *first, listint_t *second)
{ 
    // If first linked list is empty 
    if (!first) 
        return second; 
  
    // If second linked list is empty 
    if (!second) 
        return first; 
  
    // Pick the smaller value 
    if (first->n < second->n) 
    { 
        first->next = merge(first->next,second); 
        first->next->prev = first; 
        first->prev = NULL; 
        return first; 
    } 
    else
    { 
        second->next = merge(first,second->next); 
        second->next->prev = second; 
        second->prev = NULL; 
        return second; 
    } 
}


// Split a doubly linked list (DLL) into 2 DLLs of 
// half sizes 
listint_t *split(listint_t *head) 
{ 
    listint_t *fast = head, *slow = head;
    listint_t *temp;

    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    temp = slow->next; 
    slow->next = NULL; 
    return temp; 
}

/**
* cocktail_sort_list - sorts a doubly linked list in ascending order
*               using the cocktail sort algorithm
* @list: doubly linked list to be sorted
*
* Return: void
*/

void cocktail_sort_list(listint_t **list)
{ 
    if (!list || *list == NULL) 
        return list;
    listint_t *second = split(list); 
  
    // Recur for left and right halves 
    list = mergeSort(list); 
    second = mergeSort(second); 
  
    // Merge the two sorted halves 
    return merge(list,second); 
} 
